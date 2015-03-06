#ifndef EVENTO_BATALLA_PRODUCIDA_H_
#define EVENTO_BATALLA_PRODUCIDA_H_

#include "mensaje.h"
#include "territorio.h"

class EventoBatallaProducida : public Mensaje {
	private:
		Territorio* agresor;
		Territorio* agredido;
		int agresores_caidos;
		int defensores_caidos;

	public:
		EventoBatallaProducida(Territorio* agresor, int agresores_caidos, Territorio* agredido, int defensores_caidos) 
			: Mensaje(TipoDeMensaje::batalla_producida()) {
			this->agresor = agresor;
			this->agredido = agredido;
			this->agresores_caidos = agresores_caidos;
			this->defensores_caidos = defensores_caidos;
		}

		Territorio* get_agresor(){
			return agresor;
		}

		Territorio* get_agredido(){
			return agredido;
		}

		int get_agresores_caidos(){
			return agresores_caidos;
		}

		int get_defensores_caidos(){
			return defensores_caidos;
		}
};

#endif /* EVENTO_BATALLA_PRODUCIDA_H_ */
