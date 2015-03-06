#ifndef RONDA_H_
#define RONDA_H_

#include "jugador.h"

class Ronda {
	public:
		virtual void ordenar_turnos() = 0;
		virtual void empezar_ronda() = 0;
		virtual Jugador* get_primer_jugador() = 0;
		virtual Jugador* get_jugador_actual() = 0;
		virtual void finalizar_turno() = 0;
};

#endif /* RONDA_H_ */
