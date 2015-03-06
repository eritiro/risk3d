#ifndef ESPERANDO_DEFENSA_H_
#define ESPERANDO_DEFENSA_H_

#include "estado_belico.h"
#include "fin_del_juego.h"
#include "juego.h"
#include "batalla.h"
#include "orden_defender.h"

class EsperandoDefensa : public EstadoDelJuego {
	private:
		Batalla batalla;

		void preguntar_defensa(Jugador* jugador_agredido);

	public:
		EsperandoDefensa(Batalla batalla);
		void inicializar(Juego* juego);
		EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
};


#endif /* ESPERANDO_DEFENSA_H_ */
