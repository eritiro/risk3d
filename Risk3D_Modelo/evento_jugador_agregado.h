#ifndef EVENTO_JUGADOR_AGREGADO_H_
#define EVENTO_JUGADOR_AGREGADO_H_

#include "mensaje.h"

class EventoJugadorAgregado : public Mensaje {		
	private:
		Imperio* imperio;	
	public:
		EventoJugadorAgregado(Imperio* imperio) 
			: Mensaje(TipoDeMensaje::jugador_agregado()), imperio(imperio) {
		}

		Imperio* get_imperio(){
			return this->imperio;
		}
};


#endif /* EVENTO_JUEGADOR_AGREGADO_H_ */
