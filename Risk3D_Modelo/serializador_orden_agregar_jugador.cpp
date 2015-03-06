#include "serializador_orden_agregar_jugador.h"

void SerializadorOrdenAgregarJugador::serializar(Escritor& escritor, Orden& orden){
	OrdenAgregarJugador orden_especifica = dynamic_cast<OrdenAgregarJugador&>(orden);
	escritor.escribir("nombre", orden_especifica.get_nombre());
	escritor.escribir("color", orden_especifica.get_color());
	escritor.escribir("creador", orden_especifica.es_creador_del_juego());
}

Orden* SerializadorOrdenAgregarJugador::deserializar(Lector& lector, InfoJuego& info){
	string nombre = lector.leer_string("nombre");
	ColorImperio color = (ColorImperio)lector.leer_int("color");	
	bool es_creador = (ColorImperio)lector.leer_bool("creador");	
	return FabricaDeOrdenes::crear_orden_agregar_jugador(nombre, color, es_creador);
}
