#ifndef MANEJADOR_MENSAJE_JUEGO_CANCELADO_H_
#define MANEJADOR_MENSAJE_JUEGO_CANCELADO_H_

#include "manejador_de_mensajes.h"

class ManejadorMensajeJuegoCancelado : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			controlador.get_vista().mostrar_alerta("El juego ha sido cancelado.");	
			controlador.get_vista().cerrar();
		}
};

#endif /* MANEJADOR_MENSAJE_JUEGO_CANCELADO_H_ */
