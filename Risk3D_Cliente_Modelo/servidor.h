#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include "orden.h"
#include "mensaje.h"
#include "info_juego.h"

class Servidor {
	public:
		virtual void enviar(Orden* orden) = 0;
		virtual Mensaje* get_mensaje() = 0;
		
		virtual InfoJuego* get_info() = 0;

		virtual bool get_juego_terminado() = 0;

		virtual ~Servidor(){
		}
};


#endif /* SERVIDOR_H_ */
