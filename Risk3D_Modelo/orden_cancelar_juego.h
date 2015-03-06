#ifndef ORDEN_CANCELAR_JUEGO_H_
#define ORDEN_CANCELAR_JUEGO_H_

#include "orden.h"

class OrdenCancelarJuego : public Orden {		
	public:
		OrdenCancelarJuego(): Orden(TipoDeOrden::cancelar_el_juego()){
		};
};

#endif /* ORDEN_CANCELAR_JUEGO_H_ */
