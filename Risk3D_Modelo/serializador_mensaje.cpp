#include "serializador_mensaje.h"

static Log log("SerializadorMensaje");

SerializadorMensaje::SerializadorMensaje(){

	this->registrar(TipoDeMensaje::juego_iniciado(), new SerializadorMensajeEstandar<EventoJuegoIniciado>());
	this->registrar(TipoDeMensaje::juego_cancelado(), new SerializadorMensajeEstandar<EventoJuegoCancelado>());
	this->registrar(TipoDeMensaje::comienzo_turno(), new SerializadorMensajeEstandar<EventoComienzoTurno>());
	this->registrar(TipoDeMensaje::jugador_agregado(), new SerializadorEventoJugadorAgregado());
	this->registrar(TipoDeMensaje::juego_terminado(), new SerializadorEventoJuegoTerminado());
	this->registrar(TipoDeMensaje::defensa_requerida(), new SerializadorDefensaRequerida());
	this->registrar(TipoDeMensaje::actualizacion(), new SerializadorActualizacion());
	this->registrar(TipoDeMensaje::batalla_producida(), new SerializadorEventoBatallaProducida());
	this->registrar(TipoDeMensaje::mensaje_de_error(), new SerializadorMensajeDeError());
	this->registrar(TipoDeMensaje::mensaje_de_sistema(), new SerializadorMensajeDeSistema());
	this->registrar(TipoDeMensaje::mensaje_de_chat(), new SerializadorMensajeDeChat());
	this->registrar(TipoDeMensaje::mensaje_objetivo_secreto(), new SerializadorMensajeObjetivoSecreto());
}

SerializadorMensaje::~SerializadorMensaje(){
	foreach(IteradorSerializadoresMensaje, i, this->serializadores)
		delete i->second;
}

void SerializadorMensaje::serializar(Escritor& escritor, Mensaje& mensaje){
	string tipo = mensaje.get_tipo().get_clave();
	escritor.abrir_nodo("mensaje");
	escritor.escribir("tipo", tipo);
	
	SerializadorMensajeEspecifico* serializador = this->serializadores[tipo];
	if(serializador==0)
		lanzar_excepcion_serializador_especifico(tipo);

	serializador->serializar(escritor, mensaje);
	escritor.cerrar_nodo();
}

Mensaje* SerializadorMensaje::deserializar(Lector& lector, InfoJuego& info){
	lector.visitar_nodo("mensaje");
	string tipo = lector.leer_string("tipo");
	
	SerializadorMensajeEspecifico* serializador = this->serializadores[tipo];
	if(serializador==0)
		this->lanzar_excepcion_serializador_especifico(tipo);

	Mensaje* mensaje = serializador->deserializar(lector, info);
	lector.salir_nodo();
	return mensaje;
}

void SerializadorMensaje::registrar(TipoDeMensaje& tipo, SerializadorMensajeEspecifico* serializador){
	this->serializadores[tipo.get_clave()] = serializador;
}

void SerializadorMensaje::lanzar_excepcion_serializador_especifico(string tipo){
	string descripcion = "No existe un serializador especifico para el mensaje de tipo \"" + tipo + "\"";
	log.alerta(descripcion);
	throw ExcepcionDeSerializacion(descripcion);
}