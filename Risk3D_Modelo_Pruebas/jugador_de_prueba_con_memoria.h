#ifndef JUGADOR_DE_PRUEBA_CON_MEMORIA_H_
#define JUGADOR_DE_PRUEBA_CON_MEMORIA_H_

#include "jugador.h"

class JugadorDePruebaConMemoria : public Jugador {
	private:
		Mensaje* mensaje;
		ContenedorMensajes mensajes;
	public:
		virtual void recibir_mensaje(Mensaje* mensaje);
		Mensaje* get_mensaje();
		Mensaje* get_mensaje_de_tipo(TipoDeMensaje tipo);
		bool recibio_mensaje_de_tipo(TipoDeMensaje tipo);
};


#endif /* JUGADOR_DE_PRUEBA_CON_MEMORIA_H_ */
