#include "ronda_de_prueba.h"

RondaDePrueba::RondaDePrueba(Jugador* jugador_actual){
	this->jugador_actual = jugador_actual;
	this->jugador_siguiente = 0;
}

void RondaDePrueba::set_siguiente_jugador(Jugador* jugador_siguiente){
	this->jugador_siguiente = jugador_siguiente;
}

void RondaDePrueba::ordenar_turnos(){
	// no hace nada.
}

void RondaDePrueba::empezar_ronda(){
	// no hace nada.
}

Jugador* RondaDePrueba::get_primer_jugador(){
	return 0;
}

Jugador* RondaDePrueba::get_jugador_actual(){
	return jugador_actual;
}

void RondaDePrueba::finalizar_turno(){
	if(jugador_siguiente != 0){
		jugador_actual = jugador_siguiente;
		jugador_siguiente = 0;
	}
}
