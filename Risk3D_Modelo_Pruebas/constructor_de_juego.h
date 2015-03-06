#ifndef CONSTRUCTOR_DE_JUEGO_H_
#define CONSTRUCTOR_DE_JUEGO_H_

#include "juego.h"
#include "jugador_de_prueba.h"
#include "constructor_de_mapa.h"
#include "fabrica_de_ordenes.h"
#include "ronda_de_prueba.h"
#include "ambiente_de_prueba.h"

class ConstructorDeJuego {
	private:
		Juego* juego;
		RondaDePrueba* ronda;
		ConstructorDeJuego(Mapa& mapa);
	public:
		static ConstructorDeJuego crear_juego();
		static ConstructorDeJuego crear_juego(Mapa& mapa);
		ConstructorDeJuego agregar_jugador();
		ConstructorDeJuego agregar_jugador(Jugador* jugador);
		ConstructorDeJuego asignar_territorio(Territorio* territorio, Jugador* jugador, int cantidad_ejercitos);
		ConstructorDeJuego en_estado(EstadoDelJuego* estado);
		ConstructorDeJuego es_el_turno_de(Jugador* jugador);
		ConstructorDeJuego despues_juega(Jugador* jugador);
		ConstructorDeJuego usando_estos_dados(int d1, int d2 = 0, int d3 = 0, int d4 = 0);
		Juego* get_juego();

};

#endif /* CONSTRUCTOR_DE_JUEGO_H_ */
