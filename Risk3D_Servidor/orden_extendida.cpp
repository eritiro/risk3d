#include "orden_extendida.h"

OrdenExtendida::OrdenExtendida(Orden* orden, Jugador* jugador) 
	: orden(orden), jugador(jugador){
}

Orden* OrdenExtendida::get_orden(){
	return this->orden;
}

Jugador* OrdenExtendida::get_jugador(){
	return this->jugador;
}
