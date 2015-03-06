#ifndef EVENTO_COMIENZO_TURNO_H_
#define EVENTO_COMIENZO_TURNO_H_

#include "mensaje.h"

class EventoComienzoTurno : public Mensaje {		
	public:
		EventoComienzoTurno() : Mensaje(TipoDeMensaje::comienzo_turno()) {
		}
};


#endif /* EVENTO_COMIENZO_TURNO_H_ */
