#include "servidor_remoto.h"

static Log log("ServidorRemoto");

ServidorRemoto::ServidorRemoto(string servidor, int puerto){
	this->socket.conectar(servidor, puerto);
	this->mensajes_recibidos = 0;
	this->mapa = 0;
	this->info = 0;
}

ServidorRemoto::~ServidorRemoto(){
	if(this->info)
		delete info;
	if(this->mapa)
		delete mapa;
	this->socket.desconectar();
	this->unir();
}

// Corre en el hilo propio
void ServidorRemoto::ejecutar(){
	log.info("Se inició el hilo de recepción de datos del servidor.");
	try{
		
		while(socket.esta_conectado()){
			string buffer = socket.recibir(DIGITOS_MEDIDA_DEL_PAQUETE);
			int medida_mensaje = UtilidadesString::string_a_int(buffer);		

			buffer = socket.recibir(medida_mensaje);
			this->agregar_mensaje_string(buffer);
		}
	}
	catch(ExcepcionSocketCerrado){
		log.info("Se interrumpio la conexion con el socket servidor.");

		EscritorDeXml escritor;
		Mensaje* mensaje = FabricaDeMensajes::crear_evento_juego_cancelado();
		serializador_mensaje.serializar(escritor, *mensaje);
		string orden_serializada = escritor.get_xml();
		this->agregar_mensaje_string(orden_serializada);
		delete mensaje;
	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida."));
	}

	log.info("Finalizó el hilo de recepción de datos de servidor.");
	socket.desconectar();
}

// Corre en el hilo propio
void ServidorRemoto::agregar_mensaje_string(string mensaje){
	Lock lock(mutex);
	mensajes.push(mensaje);
}

// Corre en el hilo principal
string ServidorRemoto::get_mensaje_string(){
	Lock lock(mutex);
	if(mensajes.empty())
		return "";
	else{
		string mensaje = mensajes.front();
		mensajes.pop();
		return mensaje;
	}
}

// Corre en el hilo principal
Mensaje* ServidorRemoto::get_mensaje(){
	
	string mensaje_string = this->get_mensaje_string();
	if(mensaje_string == "")
		return 0;
	
	mensajes_recibidos++;


	
	// el primer mensaje es un mapa
	if(mensajes_recibidos == 1){
		LectorDeXml lector_mapa = LectorDeXml::crear_lector_de_memoria(mensaje_string);
		SerializadorMapa serializador_mapa;
		this->mapa = serializador_mapa.deserializar(lector_mapa);
		this->info = new InfoJuego(*mapa);
		return 0;
	}
	// el segundo mensaje es la textura
	else if(mensajes_recibidos == 2){
		this->mapa->set_ruta_textura(RUTA_TEXTURA_RECIBIDA);
		std::ofstream archivo_textura(RUTA_TEXTURA_RECIBIDA, std::ios_base::binary);
		archivo_textura.write(mensaje_string.c_str(), mensaje_string.length());
		archivo_textura.flush();
		return 0;
	}
	
	LectorDeXml lector = LectorDeXml::crear_lector_de_memoria(mensaje_string);
	Mensaje* mensaje = serializador_mensaje.deserializar(lector, *info);
	
	if(mensaje->es_de_tipo(TipoDeMensaje::actualizacion())){
		if(info)
			delete info;
		this->info = dynamic_cast<Actualizacion*>(mensaje)->get_info();
	}

	return mensaje;
}

// Corre en el hilo principal
void ServidorRemoto::enviar(Orden* orden){
	EscritorDeXml escritor;
	serializador_orden.serializar(escritor, *orden);
	string orden_serializada = escritor.get_xml();
	string medida = UtilidadesString::int_a_string(orden_serializada.size(), DIGITOS_MEDIDA_DEL_PAQUETE);
	socket.enviar(medida);
	socket.enviar(orden_serializada);
	delete orden;
}

// Corre en el hilo principal
bool ServidorRemoto::get_juego_terminado(){
	return !socket.esta_conectado();
}

// Corre en el hilo principal
InfoJuego* ServidorRemoto::get_info(){
	return this->info;
}
