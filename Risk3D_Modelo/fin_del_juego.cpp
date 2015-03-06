#include "fin_del_juego.h"

FinDelJuego::FinDelJuego() : EstadoDelJuego("Fin del juego"){
}

void FinDelJuego::inicializar(Juego* juego){
	juego->notificar_a_todos("El juego termino!");

	Jugador* ganador = 0;

	foreach(IteradorJugadores, jugador, juego->get_jugadores()){
		Objetivo* objetivo = (*jugador)->get_objetivo();
		if(objetivo->fue_cumplido((*jugador)->get_imperio(), &juego->get_info())){
			ganador = *jugador;
		}
	}

	if(ganador!=0){
		juego->notificar_a_todos("El ganador es " + ganador->get_nombre_emperador() + "!!!");
		foreach(IteradorJugadores, i, juego->get_jugadores()){
			(*i)->recibir_mensaje(FabricaDeMensajes::crear_evento_juego_terminado(ganador->get_imperio(), ganador->get_objetivo()));
		}
	}
}
