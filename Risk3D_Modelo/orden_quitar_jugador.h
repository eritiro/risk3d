#ifndef ORDEN_QUITAR_JUGADOR_H_
#define ORDEN_QUITAR_JUGADOR_H_

#include "orden.h"

class OrdenQuitarJugador : public Orden {		
	public:
		OrdenQuitarJugador(): Orden(TipoDeOrden::quitar_jugador()){
		};
};

#endif /* ORDEN_COMENZAR_JUEGO_H_ */
