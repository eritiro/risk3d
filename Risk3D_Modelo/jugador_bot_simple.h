#ifndef JUGADOR_BOT_SIMPLE_H_
#define JUGADOR_BOT_SIMPLE_H_

#include "jugador_bot.h"
#include "log.h"
#include "fabrica_de_ordenes.h"

class JugadorBotSimple : public JugadorBot {
	private:
		Juego& juego;
		ContenedorMensajes mensajes;

		void procesar_mensaje(Mensaje* mensaje);
		void borrar_mensajes();
	public:
		JugadorBotSimple(Juego& juego);
		~JugadorBotSimple();
		void recibir_mensaje(Mensaje* mensaje);
		void jugar();
};

#endif /* JUGADOR_BOT_SIMPLE_H_ */
