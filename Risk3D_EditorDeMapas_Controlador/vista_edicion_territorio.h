#ifndef VISTA_EDICION_TERRITORIO_H_
#define VISTA_EDICION_TERRITORIO_H_

#include "vista_contexto.h"
#include "contexto_editor.h"
#include "controlador_edicion_territorio.h"
#include <string>

using std::string;

class VistaEdicionTerritorio : public VistaContexto<ControladorEdicionTerritorio> {
	public:			
		VistaEdicionTerritorio(ContextoEditor* contexto) : VistaContexto<ControladorEdicionTerritorio>(contexto){}
		virtual void cerrar() = 0;
		virtual void set_coordenadas(int x, int y) = 0;
		virtual void set_continentes(ContenedorContinentes* continentes) = 0;
		virtual void set_continentes(ContenedorContinentes* continentes, Continente* continente) = 0;
		virtual int get_coordenada_x() = 0;
		virtual int get_coordenada_y() = 0;
		virtual string get_nombnre_continente() = 0;
		virtual string get_nombre_territorio() = 0;
		virtual void set_nombre_territorio(string nombre_territorio) = 0;
		virtual void mostrar_alerta(string mensaje) = 0;

};

#endif /* VISTA_EDICION_TERRITORIO_H_ */