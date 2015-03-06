#ifndef ASIGNANDO_INICIALMENTE_TROPAS_H_
#define ASIGNANDO_INICIALMENTE_TROPAS_H_

#include "estado_del_juego.h"
#include "juego.h"

#include "orden_reforzar_territorio.h"
#include "orden_terminar_turno.h"

class ReforzandoTerritorios;

class AsignandoInicialmenteTropas : public EstadoDelJuego {
	public:
		AsignandoInicialmenteTropas();
		void inicializar(Juego* juego);
		EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
};


#endif /* ASIGNANDO_INICIALMENTE_TROPAS_H_ */
