#include "jugador_de_prueba_con_memoria.h"

void JugadorDePruebaConMemoria::recibir_mensaje(Mensaje* mensaje){
	this->mensaje = mensaje;
	mensajes.push_back(mensaje);
}

Mensaje* JugadorDePruebaConMemoria::get_mensaje(){
	return this->mensaje;
}

Mensaje* JugadorDePruebaConMemoria::get_mensaje_de_tipo(TipoDeMensaje tipo){
	foreach(IteradorMensajes, i, mensajes){
		if((*i)->es_de_tipo(tipo))
			return *i;
	}
	// else
	return 0;
}

bool JugadorDePruebaConMemoria::recibio_mensaje_de_tipo(TipoDeMensaje tipo){
	return get_mensaje_de_tipo(tipo) != 0;
}
