#ifndef MANEJADOR_MENSAJE_DE_CHAT_H_
#define MANEJADOR_MENSAJE_DE_CHAT_H_

#include "manejador_de_mensajes.h"
#include "mensaje_de_chat.h"

class ManejadorMensajeDeChat : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			MensajeDeChat& mensaje_de_chat = dynamic_cast<MensajeDeChat&>(mensaje);
			controlador.get_vista().mostrar_mensaje_de_chat(mensaje_de_chat.get_imperio(), mensaje_de_chat.get_mensaje());	
		}
};

#endif /* MANEJADOR_MENSAJE_DE_CHAT_H_ */
