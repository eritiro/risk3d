#ifndef REFORZANDO_TERRITORIOS_H_
#define REFORZANDO_TERRITORIOS_H_

#include "estado_belico.h"
#include "orden_reforzar_territorio.h"
#include "atacando.h"

class ReforzandoTerritorios : public EstadoBelico {
	private:
		void agregar_ejercitos_refuerzo_por_territorio(Imperio* imperio, Juego* juego);
		void agregar_ejercitos_refuerzo_por_continente(Imperio* imperio, Juego* juego);
	protected:
		EstadoDelJuego* proximo_estado_guerra(Juego* juego);
	public:
		ReforzandoTerritorios();
		void inicializar(Juego* juego);
		EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
};


#endif /* REFORZANDO_TERRITORIOS_H_ */
