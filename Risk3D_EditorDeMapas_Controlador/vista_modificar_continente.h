#ifndef VISTA_MODIFICAR_CONTINENTE_H_
#define VISTA_MODIFICAR_CONTINENTE_H_

#include "vista_contexto.h"
#include "controlador_modificar_continente.h"
#include <string>

using namespace std;

class VistaModificarContinente : public VistaContexto<ControladorModificarContinente> {
	public:
		VistaModificarContinente(ContextoEditor* contexto) : VistaContexto<ControladorModificarContinente>(contexto){}
		virtual void set_continentes(ContenedorContinentes* continentes) = 0;
		virtual void set_continente_seleccionado(ContenedorContinentes* continentes, string nombre_continente_seleccionado) = 0;
		virtual string get_nombre_continente_seleccionado() = 0;
		virtual string get_nuevo_nombre_continente() = 0;
		virtual string get_nuevo_bonus_continente() = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void cerrar() = 0;
};

#endif /* VISTA_MODIFICAR_CONTINENTE_H_ */
