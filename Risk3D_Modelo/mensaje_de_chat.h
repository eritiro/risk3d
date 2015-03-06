#ifndef MENSAJE_DE_CHAT_H_
#define MENSAJE_DE_CHAT_H_

#include "mensaje.h"
#include "imperio.h"

class MensajeDeChat : public Mensaje {		
	private:
		Imperio* imperio;
		string mensaje;
	public:
		MensajeDeChat(Imperio* imperio, string mensaje)
			: Mensaje(TipoDeMensaje::mensaje_de_chat()), mensaje(mensaje){
			this->imperio = imperio;
		};

		string get_descripcion() { return imperio->get_nombre_emperador() + " dice: " + mensaje; }
		string get_mensaje() { return mensaje; }
		Imperio* get_imperio() { return imperio; }
};


#endif /* MENSAJE_DE_CHAT_H_ */
