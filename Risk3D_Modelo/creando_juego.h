#ifndef CREANDO_JUEGO_H_
#define CREANDO_JUEGO_H_

#include "estado_del_juego.h"
#include "juego.h"

#include "orden_agregar_jugador.h"
#include "orden_comenzar_juego.h"
#include "asignando_inicialmente_tropas.h"
#include "constantes.h"
#include "fabrica_de_mensajes.h"

#include "repartidor_de_territorios.h"
#include "repartidor_de_objetivos.h"

class CreandoJuego : public EstadoDelJuego {
	private:
		void agregar_jugador(string nombre, ColorImperio color, Jugador* jugador, Juego* juego, bool es_creador);
		void crear_juego(Juego* juego, Jugador* jugador);

	public:
		CreandoJuego();
		EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
};


#endif /* CREANDO_JUEGO_H_ */
