#ifndef VISTA_PANTALLA_SELECCION_DE_IMPERIO_H_
#define VISTA_PANTALLA_SELECCION_DE_IMPERIO_H_

#include <string>
#include "vista_contexto.h"
#include "controlador_pantalla_seleccion_de_imperio.h"
#include "color_imperio.h"


using std::string;

class VistaPantallaSeleccionDeImperio : public VistaContexto<ControladorPantallaSeleccionDeImperio> {
	public:			
		VistaPantallaSeleccionDeImperio(ContextoJuego* contexto) : VistaContexto<ControladorPantallaSeleccionDeImperio>(contexto){}
		virtual string get_nombre_emperador() = 0;
		virtual ColorImperio get_color_imperio() = 0;
		virtual void mostrar_pantalla_previa_al_juego() = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void cerrar() = 0;
};

#endif /* VISTA_PANTALLA_SELECCION_DE_IMPERIO_H_ */
