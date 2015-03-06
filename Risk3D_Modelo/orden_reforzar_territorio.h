#ifndef ORDEN_REFORZAR_TERRITORIO_H_
#define ORDEN_REFORZAR_TERRITORIO_H_

#include "orden.h"
#include "jugador.h"
#include "excepcion_de_usuario.h"

class Juego;

class OrdenReforzarTerritorio : public Orden {
	private:
		Territorio* territorio;
		int cantidad_ejercitos;

	public:
		OrdenReforzarTerritorio(Territorio* territorio, int cantidad_ejercitos);
		Territorio* get_territorio();
		int get_cantidad_ejercitos();
		void ejecutar(Juego* juego, Jugador* jugador);
};


#endif /* ORDEN_REFORZAR_TERRITORIO_H_ */
