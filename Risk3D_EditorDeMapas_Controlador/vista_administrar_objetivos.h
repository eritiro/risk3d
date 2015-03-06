#ifndef VISTA_ADMINISTRAR_OBJETIVOS_H_
#define VISTA_ADMINISTRAR_OBJETIVOS_H_


#pragma warning(disable:4786)


#include "vista_contexto.h"
#include "contexto_editor.h"
#include "controlador_administrar_objetivos.h"
#include <string>

using std::string;

class VistaAdministrarObjetivos : public VistaContexto<ControladorAdministrarObjetivos> {
	public:			
		VistaAdministrarObjetivos(ContextoEditor* contexto) : VistaContexto<ControladorAdministrarObjetivos>(contexto){}
		virtual void cerrar() = 0;
		virtual void set_requisitos(ContenedorRequisitos contenedor_requisitos) = 0;
		virtual void abrir_ventana_edicion_objetivo() = 0;
		virtual void mostrar_mensaje_alerta(string mensaje) = 0;
		virtual void actualizar(ContenedorRequisitos contenedor_requisitos) = 0;
};


#endif /* VISTA_ADMINISTRAR_OBJETIVOS_H_ */