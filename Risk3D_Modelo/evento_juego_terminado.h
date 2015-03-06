#ifndef EVENTO_JUEGO_TERMINADO_H_
#define EVENTO_JUEGO_TERMINADO_H_

#include "mensaje.h"
#include "imperio.h"
#include "objetivo.h"

class EventoJuegoTerminado : public Mensaje {		
	private:
		Imperio* ganador;
		string objetivo;

	public:
		EventoJuegoTerminado(Imperio* ganador, Objetivo* objetivo) : Mensaje(TipoDeMensaje::juego_terminado()) {
			this->ganador = ganador;
			this->objetivo = objetivo->get_descripcion();
		}

		EventoJuegoTerminado(Imperio* ganador, string objetivo) : Mensaje(TipoDeMensaje::juego_terminado()) {
			this->ganador = ganador;
			this->objetivo = objetivo;
		}

		Imperio* get_imperio_ganador(){
			return this->ganador;
		}

		string get_objetivo(){
			return this->objetivo;
		}
};


#endif /* EVENTO_JUEGO_TERMINADO_H_ */
