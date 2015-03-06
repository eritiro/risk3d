#ifndef MANEJADOR_DE_MENSAJES_H_
#define MANEJADOR_DE_MENSAJES_H_

#include "controlador_pantalla_juego.h"

class ManejadorDeMensajes {	
	public:
		virtual void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador) = 0;
};

#endif /* MANEJADOR_DE_MENSAJES_H_ */
