#ifndef MENSAJE_DE_SISTEMA_H_
#define MENSAJE_DE_SISTEMA_H_

#include "mensaje.h"

class MensajeDeSistema : public Mensaje {		
	private:
		string mensaje;
	public:
		MensajeDeSistema(string mensaje): Mensaje(TipoDeMensaje::mensaje_de_sistema()), mensaje(mensaje){
		};

		string get_descripcion() { return "Mensaje de sistema: " + mensaje; }
		string get_mensaje() { return mensaje; }
};


#endif /* MENSAJE_DE_SISTEMA_H_ */
