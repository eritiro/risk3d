#ifndef DEFENSA_REQUERIDA_H_
#define DEFENSA_REQUERIDA_H_

#include "mensaje.h"

class DefensaRequerida : public Mensaje {
	private:
		Territorio* territorio_agresor;
		Territorio* territorio_agredido;
		int ejercitos_ataque;
	public:
		
		DefensaRequerida(Territorio* territorio_agresor, Territorio* territorio_agredido, int ejercitos_ataque) 
			: Mensaje(TipoDeMensaje::defensa_requerida()) {
			this->territorio_agresor = territorio_agresor;
			this->territorio_agredido = territorio_agredido;
			this->ejercitos_ataque = ejercitos_ataque;
		}

		Territorio* get_territorio_agresor(){
			return this->territorio_agresor;
		}

		Territorio* get_territorio_agredido(){
			return this->territorio_agredido;
		}

		int get_ejercitos_ataque(){
			return this->ejercitos_ataque;
		}
};

#endif /* DEFENSA_REQUERIDA_H_ */
