#ifndef MANEJADOR_MENSAJE_OBJETIVO_SECRETO_H_
#define MANEJADOR_MENSAJE_OBJETIVO_SECRETO_H_

#include "manejador_de_mensajes.h"

class ManejadorMensajeObjetivoSecreto : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			MensajeObjetivoSecreto& mensaje_objetivo_secreto = dynamic_cast<MensajeObjetivoSecreto&>(mensaje);
			
			controlador.set_objetivo_secreto(mensaje_objetivo_secreto.get_contenido());
		}
};

#endif /* MANEJADOR_MENSAJE_OBJETIVO_SECRETO_H_ */
