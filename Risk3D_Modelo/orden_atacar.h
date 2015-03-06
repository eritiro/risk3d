#ifndef ORDEN_ATACAR_H_
#define ORDEN_ATACAR_H_

#include "orden.h"
#include "territorio.h"


class OrdenAtacar : public Orden {
	private:
		Territorio* origen;
		Territorio* destino;
		int cantidad_ejercitos;
	public:
		OrdenAtacar(Territorio* origen, Territorio* destino, int cantidad_ejercitos);
		Territorio* get_origen();
		Territorio* get_destino();
		int get_cantidad_ejercitos();
};


#endif /* ORDEN_ATACAR_H_ */
