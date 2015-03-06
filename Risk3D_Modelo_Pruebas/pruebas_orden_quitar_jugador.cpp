#include <cppunit/config/SourcePrefix.h>
#include "pruebas_orden_quitar_jugador.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PruebasOrdenQuitarJugador);

void PruebasOrdenQuitarJugador::ordenar_quitar_jugador_el_juego_debe_quitar_al_jugador(){
	Juego* juego = ConstructorDeJuego::crear_juego()
					.agregar_jugador()
					.agregar_jugador()
					.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_quitar_jugador(), juego->get_jugadores().back());

	CPPUNIT_ASSERT(juego->get_jugadores().size() == 1);
}

void PruebasOrdenQuitarJugador::ordenar_quitar_jugador_con_jugador_inexistente_el_juego_no_debe_quitar_al_jugador(){
	Juego* juego = ConstructorDeJuego::crear_juego()
					.agregar_jugador()
					.agregar_jugador()
					.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_quitar_jugador(), &JugadorDePrueba());

	CPPUNIT_ASSERT(juego->get_jugadores().size() == 2);
}


