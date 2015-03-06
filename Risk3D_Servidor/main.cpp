#include "log.h"

#include "constructor_de_mapa.h"
#include "juego.h"
#include "jugador_remoto.h"
#include "fabrica_de_ordenes.h"
#include "escritor_de_xml.h"
#include "lector_de_xml.h"
#include "serializador_mapa.h"
#include "serializador_orden.h"
#include "proveedor_de_ordenes_desde_archivo.h"
#include "proveedor_de_ordenes_remotas.h"
#include "ambiente_desde_archivo.h"
#include "parser_de_parametros.h"
#include "utilidades_archivo.h"

static Log log("Servidor");

Mapa* leer_mapa(string nombre_archivo){
	log.info("Cargando mapa");
	SerializadorMapa serializador_mapa;
	
	/*
	Mapa* mapa = new Mapa();
	ConstructorDeMapa c(*mapa);
	Continente* hola1 = c.agregar_continente("hola1", 1);
	Continente* hola2 = c.agregar_continente("hola2", 1);
	Continente* hola3 = c.agregar_continente("hola1", 1);
	Continente* hola4 = c.agregar_continente("hola2", 1);
	Territorio* terri1 = c.agregar_territorio("fla1", Coordenada(10,10), hola1);
	Territorio* terri2 = c.agregar_territorio("fla2", Coordenada(10,10), hola2);
	Territorio* terri3 = c.agregar_territorio("fla3", Coordenada(10,10), hola3);
	return mapa;
	*/
	LectorDeXml lector = LectorDeXml::crear_lector_desde_archivo(nombre_archivo);
	return serializador_mapa.deserializar(lector);
}

int main(int argc, char* argv[]){

	bool salir = false;
	Mapa* mapa = 0;
	ProveedorDeOrdenes* proveedor_de_ordenes = 0;

	try{

		ParserDeParametros parser(argc, argv);

		// Lee verborragico
		Log::set_logueo_por_consola(parser.leer("verborragico") == "si");

		// Lee mapa
		string nombre_archivo_mapa = parser.leer("mapa");
		if(nombre_archivo_mapa == "")
			throw ExcepcionParseandoParametros("Debe ingresarse un mapa para ejecutar el servidor.");
		log.info("mapa    = " + nombre_archivo_mapa);
		mapa = leer_mapa(nombre_archivo_mapa);
		if(!UtilidadesArchivo::existe_archivo(mapa->get_ruta_textura()))
			throw ExcepcionRisk3D("No se puede leer la textura del mapa.");
		Juego juego(*mapa);



		// Lee debug
		bool es_debug = (parser.leer("debug") == "si");
		if(es_debug){
			log.info("debug   = si");
			string nombre_archivo_dados = parser.leer("dados");
			string nombre_archivo_ordenes = parser.leer("ordenes");
			log.info("ordenes = " + nombre_archivo_ordenes);
			log.info("dados   = " + nombre_archivo_dados);
			juego.set_componente_ambiente(new AmbienteDesdeArchivo(nombre_archivo_dados));
			proveedor_de_ordenes = new ProveedorDeOrdenesDesdeArchivo(nombre_archivo_ordenes);
		}
		else{
			log.info("debug   = no");
			int puerto = UtilidadesString::string_a_int(parser.leer("puerto"));
			// prefiero castear dos veces para estar seguro que lo que loguea es el
			// mismo valor que usa el proveedor.
			log.info("puerto = " + UtilidadesString::int_a_string(puerto));
			proveedor_de_ordenes = new ProveedorDeOrdenesRemotas(puerto, mapa);
		}

		log.info("Iniciando bucle principal del juego");
		
		while(!juego.get_juego_terminado() && !salir){
			OrdenExtendida* orden = proveedor_de_ordenes->get_orden(juego.get_info());
			if(orden!=0)
			{
				juego.procesar(orden->get_orden(), orden->get_jugador());
				delete orden;
			}
			else
				salir = true;

		}
		log.info("Juego finalizado");
	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida"));
	}

	if(proveedor_de_ordenes) delete proveedor_de_ordenes;
	if(mapa) delete mapa;
	
	return 0;
}
