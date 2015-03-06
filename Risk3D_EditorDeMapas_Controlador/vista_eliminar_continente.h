#ifndef VISTA_ELIMINAR_CONTINENTE_H_
#define VISTA_ELIMINAR_CONTINENTE_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el vector es un template
// "asi de grande".
#pragma warning(disable:4786)

#include "vista_contexto.h"
#include "contexto_editor.h"
#include "controlador_eliminar_continente.h"
#include <string>

using std::string;

class VistaEliminarContinente : public VistaContexto<ControladorEliminarContinente> {
	public:			
		VistaEliminarContinente(ContextoEditor* contexto) : VistaContexto<ControladorEliminarContinente>(contexto){}
		virtual void set_continentes(ContenedorContinentes* continentes) = 0;
		virtual void cerrar() = 0;

};

#endif /* VISTA_ELIMINAR_CONTINENTE_H_ */