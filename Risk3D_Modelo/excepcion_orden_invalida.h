#ifndef EXCEPCION_ORDEN_INVALIDA_H_
#define EXCEPCION_ORDEN_INVALIDA_H_

#include "excepcion_de_usuario.h"

// La excepcion de orden invalida es lanzada cuando un jugador intenta producir una acción que no es valida para
// el estado actual del juego. Por ejemplo: Jugar cuando no es su turno.
class ExcepcionOrdenInvalida : public ExcepcionDeUsuario {
	public:
		ExcepcionOrdenInvalida() : 
			ExcepcionDeUsuario("La orden no es valida en este momento!!") {
		}
};


#endif /* EXCEPCION_ORDEN_INVALIDA_H_ */
