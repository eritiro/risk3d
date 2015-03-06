#ifndef VISTA_CREAR_CONTINENTE_H_
#define VISTA_CREAR_CONTINENTE_H_

#include "vista_contexto.h"
#include "contexto_editor.h"
#include "controlador_crear_continente.h"
#include <string>

using std::string;

class VistaCrearContinente : public VistaContexto<ControladorCrearContinente> {
	public:			
		VistaCrearContinente(ContextoEditor* contexto) : VistaContexto<ControladorCrearContinente>(contexto){}
		virtual string get_nombre_continente() = 0;
		virtual string get_bonus_continente() = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void cerrar() = 0;

};

#endif /* VISTA_CREAR_CONTINENTE_H_ */