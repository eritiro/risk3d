#include "hilo_envio.h"

static Log log("HiloEnvio");


HiloEnvio::HiloEnvio(Socket* socket, Mapa* mapa)
	: socket(socket), mapa(mapa){
}

void HiloEnvio::encolar_para_envio(Mensaje* mensaje){
	Lock lock(mutex);
	mensajes.push(mensaje);
}

Mensaje* HiloEnvio::desencolar(){
	Lock lock(mutex);
	if(mensajes.empty()){
		return 0;
	}
	else{
		Mensaje* mensaje = mensajes.front();
		mensajes.pop();
		return mensaje;
	}
}


void HiloEnvio::enviar_mapa(){
	SerializadorMapa serializador_mapa;
	EscritorDeXml escritor;
	serializador_mapa.serializar(escritor, *mapa);
	string xml = escritor.get_xml();
	socket->enviar(UtilidadesString::int_a_string(xml.size(), DIGITOS_MEDIDA_DEL_PAQUETE));
	socket->enviar(escritor.get_xml());

	//Envia la textura:

	std::ifstream textura_archivo(mapa->get_ruta_textura().c_str(), std::ios_base::binary);

	if(!textura_archivo.is_open())
		throw ExcepcionRisk3D("No se puede leer la textura.");
	
	char* c = (char*)malloc(BUFFER_LECTURA_ARCHIVO);
	int i = 0;
#pragma warning(Esto es muy poco eficiente!)
	while(!textura_archivo.eof()){
		textura_archivo.get(c[i]);
		i++;
	}


	int medida_textura = i - 1;

	string textura_string = string(c, medida_textura);

	socket->enviar(UtilidadesString::int_a_string(medida_textura, DIGITOS_MEDIDA_DEL_PAQUETE));
	socket->enviar(textura_string);

	free(c);	
}

void HiloEnvio::ejecutar(){
	log.info("Se inicio el hilo de envio de datos al cliente.");
	try{
		this->enviar_mapa();

		while(socket->esta_conectado()){
			Thread::dormir(MILISEGUNDOS_POOLEO_ENVIO_MENSAJE);
			
			Mensaje* mensaje = desencolar();
			if(mensaje){
				EscritorDeXml escritor;
				serializador.serializar(escritor, *mensaje);
				string xml = escritor.get_xml();
				socket->enviar(UtilidadesString::int_a_string(xml.size(), DIGITOS_MEDIDA_DEL_PAQUETE));
				socket->enviar(escritor.get_xml());
			}
		}
	}
	catch(ExcepcionSocketCerrado){
		// No hace falta avisar al proveedor de ordenes porque si se rompe la conexión para el envio
		// seguramente tambien rompe la conexión para la recepcion, que es el que se encarga de
		// avisar los cambios al proveedor.
		log.info("Se interrumpio la conexion con el socket cliente.");
	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida."));
	}
	log.info("Finalizó el hilo de envio de datos al cliente.");
	socket->desconectar();
}
