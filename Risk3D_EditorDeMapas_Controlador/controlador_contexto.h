#ifndef CONTROLADOR_CONTEXTO_H_
#define CONTROLADOR_CONTEXTO_H_

#include "controlador.h"
#include "contexto_editor.h"
#include "constructor_de_mapa.h"

// Esta es la clase de la que tienen que heredar todos los controladores que necesiten usar
// el contexto del editor de mapas.
// Usar en conjunto con VistaContexto para un correcto funcionamiento.
// Salvo excepciones, usar esta como clase base para todos los controladores.
template<class T> class ControladorContexto : public Controlador<T> {
	public:	
		//devuelve el contexto para que lo puedan usar sus hijos:
		ContextoEditor* get_contexto(){
			return (ContextoEditor*)this->get_referencia_contexto();
		}

		//acceso rapido al mapa del contexto
		Mapa& get_mapa(){
			return this->get_contexto()->get_mapa();
		}

		//acceso rapido a un constructor de mapas para el mapa del contexto
		ConstructorDeMapa get_constructor(){
			return ConstructorDeMapa(this->get_mapa());
		}

};

#endif /* CONTROLADOR_CONTEXTO_H_ */
