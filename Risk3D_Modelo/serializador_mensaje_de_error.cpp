#include "serializador_mensaje_de_error.h"

void SerializadorMensajeDeError::serializar(Escritor& escritor, Mensaje& mensaje){
	MensajeDeError mensaje_especifico = dynamic_cast<MensajeDeError&>(mensaje);
	escritor.escribir("contenido", mensaje_especifico.get_mensaje());
}

Mensaje* SerializadorMensajeDeError::deserializar(Lector& lector, InfoJuego& info){
	string contenido = lector.leer_string("contenido");
	return FabricaDeMensajes::crear_mensaje_de_error(contenido);
}
