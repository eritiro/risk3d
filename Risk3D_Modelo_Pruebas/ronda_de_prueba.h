#ifndef RONDA_DE_PRUEBA_H_
#define RONDA_DE_PRUEBA_H_

#include "ronda.h"

class RondaDePrueba : public Ronda {
	private:
		Jugador* jugador_actual;
		Jugador* jugador_siguiente;

	public:
		RondaDePrueba(Jugador* jugador_actual);
		void set_siguiente_jugador(Jugador* jugador_siguiente);

		void ordenar_turnos();
		void empezar_ronda();
		Jugador* get_primer_jugador();
		Jugador* get_jugador_actual();
		void finalizar_turno();
};


#endif /* RONDA_DE_PRUEBA_H_ */
