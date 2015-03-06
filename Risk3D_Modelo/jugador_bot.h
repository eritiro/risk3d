#ifndef JUGADOR_BOT_H_
#define JUGADOR_BOT_H_

#include "jugador.h"

class JugadorBot;

typedef std::vector<JugadorBot*> ContenedorBots;
typedef ContenedorBots::iterator IteradorBots;

class JugadorBot : public Jugador, public Tranferible {
	public:
		virtual void recibir_mensaje(Mensaje* mensaje) = 0;
		virtual void jugar() = 0;
};

#endif /* JUGADOR_BOT_H_ */
