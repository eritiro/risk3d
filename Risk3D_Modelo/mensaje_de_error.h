#ifndef MENSAJE_DE_ERROR_H_
#define MENSAJE_DE_ERROR_H_

#include "mensaje.h"
#include "excepcion_de_usuario.h"

class MensajeDeError : public Mensaje {
	private:
		string mensaje;
	public:
		MensajeDeError(ExcepcionDeUsuario& ex) : Mensaje(TipoDeMensaje::mensaje_de_error()), mensaje(ex.get_descripcion()){
		};

		MensajeDeError(string mensaje) : Mensaje(TipoDeMensaje::mensaje_de_error()), mensaje(mensaje){
		};

		string get_descripcion() { return "Mensaje de error: " + mensaje; }
		string get_mensaje() { return mensaje; }
};


#endif /* MENSAJE_DE_ERROR_H_ */
