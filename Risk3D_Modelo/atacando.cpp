#pragma warning(disable:4786)

#include "atacando.h"

Atacando::Atacando() : EstadoBelico("Atacando"){
}

EstadoDelJuego* Atacando::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){
	return EstadoBelico::proximo_estado(orden, jugador, juego);
}

EstadoDelJuego* Atacando::proximo_estado_guerra(Juego* juego){
	return 0;
}
