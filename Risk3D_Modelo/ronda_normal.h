#ifndef RONDA_NORMAL_H_
#define RONDA_NORMAL_H_

#include "ronda.h"
#include "utilidades_string.h"

class Juego;

class RondaNormal : public Ronda {
	private:
		Juego& juego;
		ContenedorImperios imperios_ordenados;
		IteradorImperios iterador_imperios;
		ContenedorJugadores tirar_dados(ContenedorJugadores jugadores);
	public:
		RondaNormal(Juego& juego);
		void ordenar_turnos();
		void empezar_ronda();
		Jugador* get_primer_jugador();
		Jugador* get_jugador_actual();
		void finalizar_turno();
};


#endif /* RONDA_NORMAL_H_ */
