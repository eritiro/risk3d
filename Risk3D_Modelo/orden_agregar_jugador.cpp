#include "orden_agregar_jugador.h"

OrdenAgregarJugador::OrdenAgregarJugador(string nombre, ColorImperio color, bool es_creador_del_juego)
: Orden(TipoDeOrden::agregar_jugador()), nombre(nombre), color(color), creador_del_juego(es_creador_del_juego){
}

string OrdenAgregarJugador::get_nombre(){
	return nombre;
}

ColorImperio OrdenAgregarJugador::get_color(){
	return color;
}

bool OrdenAgregarJugador::es_creador_del_juego(){
	return creador_del_juego;
}