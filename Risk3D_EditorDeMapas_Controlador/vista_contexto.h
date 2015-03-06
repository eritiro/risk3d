#ifndef VISTA_CONTEXTO_H_
#define VISTA_CONTEXTO_H_

#include "vista.h"
#include "contexto_editor.h"

// Esta es la clase de la que tienen que heredar todas las vistas cuyos controladores 
// necesiten usar un contexto.
// Usar en conjunto con ControladorContexto para un correcto funcionamiento.
// Salvo excepciones, usar esta como clase base para todas las vistas.
template<class T> class VistaContexto : public Vista<T> {
	private:
		ContextoEditor* contexto;
	public:	
		// El unico constructor de la clase.
		// Necesita recibir como parametro un puntero de tipo ContextoEditor 
		// para que esta se lo asigne automaticamente al controlador.
		VistaContexto(ContextoEditor* contexto) : Vista<T>(contexto), contexto(contexto){
		}

		ContextoEditor* get_contexto(){
			return contexto;
		}
};

#endif /* VISTA_CONTEXTO_H_ */
