#include "serializador_actualizacion.h"

void SerializadorActualizacion::serializar(Escritor& escritor, Mensaje& mensaje){
	Actualizacion mensaje_especifico = dynamic_cast<Actualizacion&>(mensaje);

	serializador_info_juego.serializar(escritor, *mensaje_especifico.get_info());
}

Mensaje* SerializadorActualizacion::deserializar(Lector& lector, InfoJuego& info){
	
	InfoJuego* nueva_info = serializador_info_juego.deserializar(lector, info.get_mapa());

	Actualizacion* actualizacion = FabricaDeMensajes::crear_actualizacion(nueva_info);

	return actualizacion;
}
