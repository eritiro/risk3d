#ifndef CONTROLADOR_CONTEXTO_H_
#define CONTROLADOR_CONTEXTO_H_

#include "controlador.h"
#include "contexto_juego.h"

// Esta es la clase de la que tienen que heredar todos los controladores que necesiten usar
// el contexto del juego.
// Usar en conjunto con VistaContexto para un correcto funcionamiento.
// Salvo excepciones, usar esta como clase base para todos los controladores.
template<class T> class ControladorContexto : public Controlador<T> {
	public:	
		//devuelve el contexto para que lo puedan usar sus hijos:
		ContextoJuego* get_contexto(){
			return (ContextoJuego*)this->get_referencia_contexto();
		}

};

#endif /* CONTROLADOR_CONTEXTO_H_ */
