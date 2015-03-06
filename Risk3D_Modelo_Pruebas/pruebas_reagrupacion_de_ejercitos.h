#ifndef PRUEBAS_REAGRUPACION_DE_EJERCITOS_H_
#define PRUEBAS_REAGRUPACION_DE_EJERCITOS_H_

#include <cppunit/extensions/HelperMacros.h>
#include "constructor_de_juego.h"
#include "jugador_de_prueba_con_memoria.h"
#include "atacando.h"

using namespace CPPUNIT_NS;

class PruebasReagrupacionDeEjercitos: public TestFixture {
	CPPUNIT_TEST_SUITE(PruebasReagrupacionDeEjercitos);
	CPPUNIT_TEST(ordenar_reagrupar_ejercitos_debe_cambiar_de_turno);
	CPPUNIT_TEST(ordenar_reagrupar_ejercitos_debe_quitar_ejercitos_desde_el_origen);
	CPPUNIT_TEST(ordenar_reagrupar_ejercitos_debe_agregar_ejercitos_al_destino);
	CPPUNIT_TEST(ordenar_reagrupar_ejercitos_desde_territorio_ajeno_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_reagrupar_ejercitos_hacia_territorio_ajeno_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_reagrupar_mas_ejercitos_que_los_disponibles_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_reagrupar_ejercitos_fuera_de_turno_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST_SUITE_END();

	private:
		Mapa mapa;
		Territorio* territorio_a;
		Territorio* territorio_b;

	public:
		void setUp();
		// Funcionamiento positivo:
		void ordenar_reagrupar_ejercitos_debe_cambiar_de_turno();
		void ordenar_reagrupar_ejercitos_debe_quitar_ejercitos_desde_el_origen();
		void ordenar_reagrupar_ejercitos_debe_agregar_ejercitos_al_destino();

		// Validaciones:
		void ordenar_reagrupar_ejercitos_desde_territorio_ajeno_debe_devolver_mensaje_de_error();
		void ordenar_reagrupar_ejercitos_hacia_territorio_ajeno_debe_devolver_mensaje_de_error();
		void ordenar_reagrupar_mas_ejercitos_que_los_disponibles_debe_devolver_mensaje_de_error();
		void ordenar_reagrupar_ejercitos_fuera_de_turno_debe_devolver_mensaje_de_error();
};


#endif /* PRUEBAS_REAGRUPACION_DE_EJERCITOS_H_ */
