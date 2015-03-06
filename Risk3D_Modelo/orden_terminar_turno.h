#ifndef ORDEN_TERMINAR_TURNO_H_
#define ORDEN_TERMINAR_TURNO_H_

#include "orden.h"
#include "juego.h"

class OrdenTerminarTurno : public Orden {		
	public:
		OrdenTerminarTurno();
		void ejecutar(Juego* juego, Jugador* jugador);
};

#endif /* ORDEN_TERMINAR_TURNO_H_ */
