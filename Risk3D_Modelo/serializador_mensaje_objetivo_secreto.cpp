#include "serializador_mensaje_objetivo_secreto.h"

void SerializadorMensajeObjetivoSecreto::serializar(Escritor& escritor, Mensaje& mensaje){
	MensajeObjetivoSecreto mensaje_especifico = dynamic_cast<MensajeObjetivoSecreto&>(mensaje);
	escritor.escribir("contenido", mensaje_especifico.get_contenido());
}

Mensaje* SerializadorMensajeObjetivoSecreto::deserializar(Lector& lector, InfoJuego& info){
	string contenido = lector.leer_string("contenido");
	return FabricaDeMensajes::crear_mensaje_objetivo_secreto(contenido);
}
