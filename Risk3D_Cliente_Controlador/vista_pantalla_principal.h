#ifndef VISTA_PANTALLA_PRINCIPAL_H_
#define VISTA_PANTALLA_PRINCIPAL_H_

#include "vista_contexto.h"
#include "controlador_pantalla_principal.h"

class VistaPantallaPrincipal : public VistaContexto<ControladorPantallaPrincipal> {
	public:			
		VistaPantallaPrincipal(ContextoJuego* contexto) : VistaContexto<ControladorPantallaPrincipal>(contexto){}
		
		virtual void abrir_ventana_crear_juego() = 0;
		virtual void abrir_ventana_seleccion_servidor() = 0;

		virtual void cerrar() = 0;
};

#endif /* VISTA_PANTALLA_PRINCIPAL_H_ */
