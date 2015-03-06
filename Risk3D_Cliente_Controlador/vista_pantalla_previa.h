#ifndef VISTA_PANTALLA_PREVIA_H_
#define VISTA_PANTALLA_PREVIA_H_

#include "vista_contexto.h"
#include "controlador_pantalla_previa.h"
#include "imperio.h"

class VistaPantallaPrevia : public VistaContexto<ControladorPantallaPrevia> {
	public:			
		VistaPantallaPrevia(ContextoJuego* contexto) : VistaContexto<ControladorPantallaPrevia>(contexto){}
		virtual void mostrar_mensaje(string mensaje) = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void mostrar_chat(Imperio* imperio, string mensaje) = 0;

		virtual void mostrar_juego() = 0;
		virtual void cerrar() = 0;
};

#endif /* VISTA_PANTALLA_PREVIA_H_ */
