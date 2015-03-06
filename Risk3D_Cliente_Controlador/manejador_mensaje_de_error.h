#ifndef MANEJADOR_MENSAJE_DE_ERROR_H_
#define MANEJADOR_MENSAJE_DE_ERROR_H_

#include "manejador_de_mensajes.h"
#include "mensaje_de_error.h"

class ManejadorMensajeDeError : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			MensajeDeError& mensaje_de_error = dynamic_cast<MensajeDeError&>(mensaje);
			controlador.get_vista().mostrar_alerta(mensaje_de_error.get_mensaje());	
		}
};

#endif /* MANEJADOR_MENSAJE_DE_ERROR_H_ */
