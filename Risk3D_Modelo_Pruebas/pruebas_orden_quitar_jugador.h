#ifndef PRUEBAS_ORDEN_QUITAR_JUGADOR_H_
#define PRUEBAS_ORDEN_QUITAR_JUGADOR_H_

#include <cppunit/extensions/HelperMacros.h>
#include "constructor_de_juego.h"

using namespace CPPUNIT_NS;

class PruebasOrdenQuitarJugador : public TestFixture {
	CPPUNIT_TEST_SUITE(PruebasOrdenQuitarJugador);
	CPPUNIT_TEST(ordenar_quitar_jugador_el_juego_debe_quitar_al_jugador);
	CPPUNIT_TEST(ordenar_quitar_jugador_con_jugador_inexistente_el_juego_no_debe_quitar_al_jugador);
	CPPUNIT_TEST_SUITE_END();

	public:
		void ordenar_quitar_jugador_el_juego_debe_quitar_al_jugador();
		void ordenar_quitar_jugador_con_jugador_inexistente_el_juego_no_debe_quitar_al_jugador();
};


#endif /* PRUEBAS_ORDEN_QUITAR_JUGADOR_H_ */
