#ifndef MENSAJE_OBJETIVO_SECRETO_H_
#define MENSAJE_OBJETIVO_SECRETO_H_

#include "mensaje.h"
#include "objetivo.h"

class MensajeObjetivoSecreto : public Mensaje {		
	private:
		string contenido;
	public:
		MensajeObjetivoSecreto(Objetivo* objetivo): Mensaje(TipoDeMensaje::mensaje_objetivo_secreto()), contenido(objetivo->get_descripcion()){
		}

		MensajeObjetivoSecreto(string contenido): Mensaje(TipoDeMensaje::mensaje_objetivo_secreto()), contenido(contenido){
		}

		string get_contenido() { return this->contenido; }
};


#endif /* MENSAJE_OBJETIVO_SECRETO_H_ */
