#ifndef JUGADOR_DE_PRUEBA_H_
#define JUGADOR_DE_PRUEBA_H_

#include "jugador.h"
#include "log.h"

class JugadorDePrueba : public Jugador {
	public:
		virtual void recibir_mensaje(Mensaje* mensaje);
};


#endif /* JUGADOR_DE_PRUEBA_H_ */
