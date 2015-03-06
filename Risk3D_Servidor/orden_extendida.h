#ifndef ORDEN_EXTENDIDA_H_
#define ORDEN_EXTENDIDA_H_

#include "orden.h"
#include "jugador.h"


class OrdenExtendida {
	private:
		Orden* orden;
		Jugador* jugador;
	public:
		OrdenExtendida(Orden* orden, Jugador* jugador);
		Orden* get_orden();
		Jugador* get_jugador();
};

#endif /* ORDEN_EXTENDIDA_H_ */
