#include "proveedor_de_ordenes_remotas.h"

static Log log("ProveedorDeOrdenesRemotas");

ProveedorDeOrdenesRemotas::ProveedorDeOrdenesRemotas(int puerto_para_nuevas_conexiones, Mapa* mapa){
	oyente = new OyenteDePeticiones(this, puerto_para_nuevas_conexiones, mapa);
	oyente->comenzar();
	log.info("Proveedor de ordenes remotas creado.");
}

ProveedorDeOrdenesRemotas::~ProveedorDeOrdenesRemotas(){
	delete oyente;
	foreach(IteradorJugadoresRemotos, i, this->jugadores)
		delete *i;
}

bool ProveedorDeOrdenesRemotas::hay_ordenes_pendientes(){
	Lock lock(mutex);
	return !this->ordenes.empty();
}

OrdenSerializada ProveedorDeOrdenesRemotas::desencolar_orden(){
	Lock lock(mutex);
	OrdenSerializada orden = ordenes.front();
	ordenes.pop();
	return orden;
}

void ProveedorDeOrdenesRemotas::agregar_orden(string orden, JugadorRemoto* jugador){
	Lock lock(mutex);
	ordenes.push(pair<JugadorRemoto*, string>(jugador, orden));
}

OrdenExtendida* ProveedorDeOrdenesRemotas::get_orden(InfoJuego& info){
	while(!hay_ordenes_pendientes())
		Thread::dormir(MILISEGUNDOS_POOLEO_ORDEN);
	OrdenSerializada orden_serializada = desencolar_orden();

	LectorDeXml lector = LectorDeXml::crear_lector_de_memoria(orden_serializada.second);
	Orden*  orden = serializador_orden.deserializar(lector, info);

	return new OrdenExtendida(orden, orden_serializada.first);
}

void ProveedorDeOrdenesRemotas::agregar_jugador(JugadorRemoto* jugador){
	jugadores.push_back(jugador);
}

