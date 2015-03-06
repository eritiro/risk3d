#ifndef PRUEBAS_BATALLA_H_
#define PRUEBAS_BATALLA_H_

#include <cppunit/extensions/HelperMacros.h>
#include "constructor_de_juego.h"
#include "jugador_de_prueba_con_memoria.h"
#include "atacando.h"

using namespace CPPUNIT_NS;

class PruebasBatalla : public TestFixture {
	CPPUNIT_TEST_SUITE(PruebasBatalla);
	CPPUNIT_TEST(ordenar_ataque_desde_territorio_ajeno_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_ataque_a_territorio_no_limitrofe_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_ataque_a_territorio_propio_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_ataque_con_mas_de_tres_ejercitos_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_ataque_con_mas_ejercitos_de_los_disponibles_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_ataque_fuera_de_turno_debe_devolver_mensaje_de_error);
	CPPUNIT_TEST(ordenar_ataque_a_territorio_con_un_ejercito_debe_realizar_batalla);
	CPPUNIT_TEST(ordenar_ataque_a_territorio_con_mas_de_un_ejercito_debe_preguntar_con_cuantos_defender);
	CPPUNIT_TEST(crear_batalla_uno_a_uno_con_empate_debe_ganar_el_defensor);
	CPPUNIT_TEST(crear_batalla_dos_contra_dos_debe_perder_un_ejercito_cada_uno);
	CPPUNIT_TEST(crear_batalla_gana_el_defensor_el_territorio_no_debe_ser_conquistado);
	CPPUNIT_TEST(crear_batalla_gana_el_agresor_el_territorio_debe_ser_conquistado);
	CPPUNIT_TEST_SUITE_END();

	private:
		Mapa mapa;
		Territorio* territorio_a;
		Territorio* territorio_b;
		Territorio* territorio_ahislado;

	public:
		void setUp();
		//validacion
		void ordenar_ataque_desde_territorio_ajeno_debe_devolver_mensaje_de_error();
		void ordenar_ataque_a_territorio_no_limitrofe_debe_devolver_mensaje_de_error();
		void ordenar_ataque_a_territorio_propio_debe_devolver_mensaje_de_error();
		void ordenar_ataque_con_mas_de_tres_ejercitos_debe_devolver_mensaje_de_error();
		void ordenar_ataque_con_mas_ejercitos_de_los_disponibles_debe_devolver_mensaje_de_error();
		void ordenar_ataque_fuera_de_turno_debe_devolver_mensaje_de_error();

		//flujo del juego
		void ordenar_ataque_a_territorio_con_un_ejercito_debe_realizar_batalla();
		void ordenar_ataque_a_territorio_con_mas_de_un_ejercito_debe_preguntar_con_cuantos_defender();

		// pruebas de la batalla en si
		void crear_batalla_uno_a_uno_con_empate_debe_ganar_el_defensor();
		void crear_batalla_dos_contra_dos_debe_perder_un_ejercito_cada_uno();		
		void crear_batalla_gana_el_defensor_el_territorio_no_debe_ser_conquistado();
		void crear_batalla_gana_el_agresor_el_territorio_debe_ser_conquistado();
};


#endif /* PRUEBAS_BATALLA_H_ */
