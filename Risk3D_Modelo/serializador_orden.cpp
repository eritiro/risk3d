#include "serializador_orden.h"

SerializadorOrden::SerializadorOrden(){

	this->registrar(TipoDeOrden::quitar_jugador(), new SerializadorOrdenEstandar<OrdenQuitarJugador>());
	this->registrar(TipoDeOrden::comenzar_el_juego(), new SerializadorOrdenEstandar<OrdenComenzarJuego>());
	this->registrar(TipoDeOrden::cancelar_el_juego(), new SerializadorOrdenEstandar<OrdenCancelarJuego>());
	this->registrar(TipoDeOrden::terminar_turno(), new SerializadorOrdenEstandar<OrdenTerminarTurno>());
	this->registrar(TipoDeOrden::agregar_jugador(), new SerializadorOrdenAgregarJugador());
	this->registrar(TipoDeOrden::atacar(), new SerializadorOrdenAtacar());
	this->registrar(TipoDeOrden::defender(), new SerializadorOrdenDefender());
	this->registrar(TipoDeOrden::reagrupar_ejercitos(), new SerializadorOrdenReagruparEjercitos());
	this->registrar(TipoDeOrden::reforzar_territorio(), new SerializadorOrdenReforzarTerritorio());
	this->registrar(TipoDeOrden::chatear(), new SerializadorOrdenChatear());
}

SerializadorOrden::~SerializadorOrden(){
	foreach(IteradorSerializadoresOrden, i, this->serializadores)
		delete i->second;
}

void SerializadorOrden::serializar(Escritor& escritor, Orden& orden){
	string tipo = orden.get_tipo().get_clave();
	escritor.abrir_nodo("orden");
	escritor.escribir("tipo", tipo);

	SerializadorOrdenEspecifica* serializador = this->serializadores[tipo];
	if(serializador==0)
		throw ExcepcionDeSerializacion("No existe un serializador especifico para la orden de tipo \"" + tipo + "\"");
	
	serializador->serializar(escritor, orden);
	escritor.cerrar_nodo();
}

Orden* SerializadorOrden::deserializar(Lector& lector, InfoJuego& info){
	lector.visitar_nodo("orden");
	string tipo = lector.leer_string("tipo");

	SerializadorOrdenEspecifica* serializador = this->serializadores[tipo];
	if(serializador==0)
		throw ExcepcionDeSerializacion("No existe un serializador especifico para la orden de tipo \"" + tipo + "\"");

	Orden* orden = serializador->deserializar(lector, info);
	lector.salir_nodo();
	return orden;
}

void SerializadorOrden::registrar(TipoDeOrden& tipo, SerializadorOrdenEspecifica* serializador){
	this->serializadores[tipo.get_clave()] = serializador;
}
