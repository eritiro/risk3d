#ifndef ESTADO_BELICO_H_
#define ESTADO_BELICO_H_

#include "estado_del_juego.h"
#include "juego.h"
#include "batalla.h"
#include "esperando_defensa.h"
#include "fin_del_juego.h"

#include "orden_terminar_turno.h"
#include "orden_atacar.h"
#include "orden_reagrupar_ejercitos.h"

class EstadoBelico : public EstadoDelJuego {
	private:
		EstadoDelJuego* atacar(OrdenAtacar* ordenAtacar, Jugador* jugador, Juego* juego);
		EstadoDelJuego* reagrupar(OrdenReagruparEjercitos* ordenReagrupar, Jugador* jugador, Juego* juego);
	protected:
		EstadoBelico(string descripcion);
		virtual EstadoDelJuego* proximo_estado_guerra(Juego* juego) = 0;
	public:
		virtual EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
};


#endif /* ESTADO_BELICO_H_ */
