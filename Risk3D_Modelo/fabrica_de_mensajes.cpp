#include "fabrica_de_mensajes.h"

Actualizacion* FabricaDeMensajes::crear_actualizacion(InfoJuego* info){
	return new Actualizacion(info);
}

Mensaje* FabricaDeMensajes::crear_evento_juego_iniciado(){
	return new EventoJuegoIniciado();
}

Mensaje* FabricaDeMensajes::crear_evento_comienzo_turno(){
	return new EventoComienzoTurno();
}

Mensaje* FabricaDeMensajes::crear_evento_juego_cancelado(){
	return new EventoJuegoCancelado();
}

Mensaje* FabricaDeMensajes::crear_evento_jugador_agregado(Imperio* imperio){
	return new EventoJugadorAgregado(imperio);
}

Mensaje* FabricaDeMensajes::crear_mensaje_de_error(ExcepcionDeUsuario& ex){
	return new MensajeDeError(ex);
}

Mensaje* FabricaDeMensajes::crear_mensaje_de_error(string mensaje){
	return new MensajeDeError(mensaje);
}

Mensaje* FabricaDeMensajes::crear_mensaje_de_sistema(string mensaje){
	return new MensajeDeSistema(mensaje);
}

Mensaje* FabricaDeMensajes::crear_mensaje_de_chat(Imperio* imperio, string mensaje){
	return new MensajeDeChat(imperio, mensaje);
}

Mensaje* FabricaDeMensajes::crear_defensa_requerida(Territorio* territorio_agresor, Territorio* territorio_agredido, int ejercitos_ataque){
	return new DefensaRequerida(territorio_agresor, territorio_agredido, ejercitos_ataque);
}

Mensaje* FabricaDeMensajes::crear_evento_batalla_producida(Territorio* agresor, int agresores_caidos, Territorio* agredido, int defensores_caidos){
	return new EventoBatallaProducida(agresor, agresores_caidos, agredido, defensores_caidos);
}

Mensaje* FabricaDeMensajes::crear_mensaje_objetivo_secreto(Objetivo* objetivo){
	return new MensajeObjetivoSecreto(objetivo);
}

Mensaje* FabricaDeMensajes::crear_mensaje_objetivo_secreto(string contenido){
	return new MensajeObjetivoSecreto(contenido);
}

Mensaje* FabricaDeMensajes::crear_evento_juego_terminado(Imperio* imperio, Objetivo* objetivo){
	return new EventoJuegoTerminado(imperio, objetivo);
}

Mensaje* FabricaDeMensajes::crear_evento_juego_terminado(Imperio* imperio, string objetivo){
	return new EventoJuegoTerminado(imperio, objetivo);
}
