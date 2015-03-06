#ifndef VISTA_EDITAR_OBJETIVO_H_
#define VISTA_EDITAR_OBJETIVO_H_


#pragma warning(disable:4786)


#include "vista_contexto.h"
#include "contexto_editor.h"
#include "controlador_editar_objetivo.h"
#include <string>

using std::string;

class VistaEditarObjetivo : public VistaContexto<ControladorEditarObjetivo> {
	public:			
		VistaEditarObjetivo(ContextoEditor* contexto) : VistaContexto<ControladorEditarObjetivo>(contexto){}
		virtual void cerrar() = 0;
		virtual void set_continentes_default(ContenedorContinentes* contenedor_continentes) = 0;
		virtual void mostrar_mensaje_alerta(string mensaje) = 0;
		virtual void agregar_continente_valor(Continente* continente, int cantidad_territorios_seleccionado) = 0;
		virtual int get_valor_por_continente(Continente* continente) = 0;
};


#endif /* VISTA_EDITAR_OBJETIVO_H_ */