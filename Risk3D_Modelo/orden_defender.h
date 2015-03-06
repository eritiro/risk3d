#ifndef ORDEN_DEFENDER_H_
#define ORDEN_DEFENDER_H_

#include "orden.h"


class OrdenDefender : public Orden {
	private:
		int cantidad_ejercitos;
	public:
		OrdenDefender(int cantidad_ejercitos);
		int get_cantidad_ejercitos();
};


#endif /* ORDEN_DEFENDER_H_ */
