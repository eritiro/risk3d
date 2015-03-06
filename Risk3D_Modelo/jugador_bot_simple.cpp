#include "jugador_bot_simple.h"

static Log log("JugadorBotSimple");

JugadorBotSimple::JugadorBotSimple(Juego& juego) : juego(juego){
	// Forzamos a que el bot inicialmente reaccione como si fuera su turno, en caso de que no lo sea
	// el juego rechazará las ordenes que no sean validas.
	mensajes.push_back(FabricaDeMensajes::crear_evento_comienzo_turno());
}

JugadorBotSimple::~JugadorBotSimple(){
	this->borrar_mensajes();
}

void JugadorBotSimple::recibir_mensaje(Mensaje* mensaje){

	log.info(this->get_nombre_emperador() + " << " + mensaje->get_descripcion());
	mensajes.push_back(mensaje);
	
}

void JugadorBotSimple::jugar(){
	// Mientras haya mensajes, saca el primero y lo procesa.
	// Este algoritmo tiene esta forma para evitar que el juego llame a la funcion en forma recurrente
	// sin que se cumpla jamas una condicion de corte.
	while(this->mensajes.size() != 0){
		IteradorMensajes i = mensajes.begin();
		Mensaje* mensaje = *i;
		mensajes.erase(i);
		this->procesar_mensaje(mensaje);
		delete mensaje;
	}
}

void JugadorBotSimple::procesar_mensaje(Mensaje* mensaje){

	if(mensaje->es_de_tipo(TipoDeMensaje::defensa_requerida())){
		juego.procesar(FabricaDeOrdenes::crear_orden_defender(1), this);
	}
	/*
	else if(mensaje->es_de_tipo(TipoDeMensaje::comienzo_turno())){
		juego.procesar(FabricaDeOrdenes::crear_orden_terminar_turno(), this);
	}
	*/
	
}

void JugadorBotSimple::borrar_mensajes(){
	foreach(IteradorMensajes, i, this->mensajes)
		delete *i;
	this->mensajes = ContenedorMensajes();
}
