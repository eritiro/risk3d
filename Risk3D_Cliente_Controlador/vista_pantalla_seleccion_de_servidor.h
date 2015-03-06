#ifndef VISTA_PANTALLA_SELECCION_DE_SERVIDOR_H_
#define VISTA_PANTALLA_SELECCION_DE_SERVIDOR_H_

#include <string>
#include "vista_contexto.h"
#include "controlador_pantalla_seleccion_de_servidor.h"

using std::string;

class VistaPantallaSeleccionDeServidor : public VistaContexto<ControladorPantallaSeleccionDeServidor> {
	public:			
		VistaPantallaSeleccionDeServidor(ContextoJuego* contexto) : VistaContexto<ControladorPantallaSeleccionDeServidor>(contexto){}
		virtual string get_nombre_servidor() = 0;
		virtual string get_puerto_servidor() = 0;
		virtual void mostrar_seleccion_de_imperio() = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void cerrar() = 0;
};

#endif /* VISTA_PANTALLA_SELECCION_DE_SERVIDOR_H_ */
