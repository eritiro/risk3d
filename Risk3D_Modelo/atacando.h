#ifndef ATACANDO_H_
#define ATACANDO_H_

#include "estado_belico.h"
#include "juego.h"

class Atacando : public EstadoBelico {
	protected:
		EstadoDelJuego* proximo_estado_guerra(Juego* juego);

	public:
		Atacando();
		EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
};


#endif /* ATACANDO_H_ */
