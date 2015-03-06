#ifndef ORDEN_COMENZAR_JUEGO_H_
#define ORDEN_COMENZAR_JUEGO_H_

#include "orden.h"

class OrdenComenzarJuego : public Orden {		
	public:
		OrdenComenzarJuego(): Orden(TipoDeOrden::comenzar_el_juego()){
		};
};

#endif /* ORDEN_COMENZAR_JUEGO_H_ */
