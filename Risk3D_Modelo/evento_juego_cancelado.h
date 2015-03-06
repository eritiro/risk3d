#ifndef EVENTO_JUEGO_CANCELADO_H_
#define EVENTO_JUEGO_CANCELADO_H_

#include "mensaje.h"

class EventoJuegoCancelado : public Mensaje {		
	public:
		EventoJuegoCancelado() : Mensaje(TipoDeMensaje::juego_cancelado()) {
		}
};


#endif /* EVENTO_JUEGO_INICIADO_H_ */
