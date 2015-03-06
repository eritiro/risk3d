#include "proveedor_de_ordenes_desde_archivo.h"

static Log log("ProveedorDeOrdenesDesdeArchivo");

ProveedorDeOrdenesDesdeArchivo::ProveedorDeOrdenesDesdeArchivo(string nombre_archivo)
	: archivo(nombre_archivo.c_str()){		
	if(!archivo) throw ExcepcionRisk3D("No se puede abrir el archivo de ordenes");
	log.info("Proveedor de ordenes desde archivo creado");
}

ProveedorDeOrdenesDesdeArchivo::~ProveedorDeOrdenesDesdeArchivo(){
	foreach(IteradorTablaJugadores, i, jugadores)
		delete i->second;
}


OrdenExtendida* ProveedorDeOrdenesDesdeArchivo::get_orden(InfoJuego& info){

	string linea = UtilidadesString::leer_linea(archivo);
	
	if(UtilidadesString::quitar_espacios(linea) == ""){
		log.info("No hay mas ordenes en el archivo");
		return 0;
		
	}

	int numero_jugador = UtilidadesString::string_a_int(linea);

	
	if(!jugadores[numero_jugador])
		jugadores[numero_jugador] = new JugadorDePrueba();

	
	string texto_de_orden = UtilidadesString::leer_linea(archivo);

	if(UtilidadesString::quitar_espacios(texto_de_orden) != ""){
		LectorDeXml lector = LectorDeXml::crear_lector_de_memoria(texto_de_orden);
		return new OrdenExtendida(serializador.deserializar(lector, info), jugadores[numero_jugador]);
		//return new OrdenExtendida(FabricaDeOrdenes::crear_orden_agregar_jugador("lala", AZUL), jugadores[numero_jugador]);
	}
	else {
		log.info("No hay mas ordenes en el archivo");
		return 0;
	}

}
