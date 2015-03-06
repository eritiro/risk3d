#ifndef ORDEN_REAGRUPAR_EJERCITOS_H_
#define ORDEN_REAGRUPAR_EJERCITOS_H_

#include "orden.h"
#include "territorio.h"

class OrdenReagruparEjercitos : public Orden {
	private:
		Territorio* origen;
		Territorio* destino;
		int cantidad_ejercitos;

	public:
		OrdenReagruparEjercitos(Territorio* origen, Territorio* destino, int cantidad_ejercitos);
		Territorio* get_origen();
		Territorio* get_destino();
		int get_cantidad_ejercitos();

};


#endif /* ORDEN_REAGRUPAR_EJERCITOS_H_ */
