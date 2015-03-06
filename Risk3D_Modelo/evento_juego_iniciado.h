#ifndef EVENTO_JUEGO_INICIADO_H_
#define EVENTO_JUEGO_INICIADO_H_

#include "mensaje.h"

class EventoJuegoIniciado : public Mensaje {		
	public:
		EventoJuegoIniciado() : Mensaje(TipoDeMensaje::juego_iniciado()) {
		}
};


#endif /* EVENTO_JUEGO_INICIADO_H_ */
