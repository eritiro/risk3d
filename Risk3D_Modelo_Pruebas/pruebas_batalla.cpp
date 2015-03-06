#include <cppunit/config/SourcePrefix.h>
#include "pruebas_batalla.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PruebasBatalla);

void PruebasBatalla::setUp(){
	//Crea un mapa para las pruebas:
	ConstructorDeMapa constructor(mapa);
	Continente* continente = constructor.agregar_continente("Continente de Pruebas", 1000);
	territorio_a = constructor.agregar_territorio("territorio a", Coordenada(10,10), continente);
	territorio_b = constructor.agregar_territorio("territorio b", Coordenada(20,20), continente);
	territorio_ahislado = constructor.agregar_territorio("territorio ahislado", Coordenada(20,20), continente);
	constructor.agregar_adyacencia(territorio_a, territorio_b);
}

void PruebasBatalla::ordenar_ataque_desde_territorio_ajeno_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &antagonista, 5)
		.asignar_territorio(territorio_b, &antagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasBatalla::ordenar_ataque_a_territorio_no_limitrofe_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_ahislado, &antagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_ahislado, 1), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasBatalla::ordenar_ataque_a_territorio_propio_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &protagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasBatalla::ordenar_ataque_con_mas_de_tres_ejercitos_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 10)
		.asignar_territorio(territorio_b, &antagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 4), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasBatalla::ordenar_ataque_con_mas_ejercitos_de_los_disponibles_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 2)
		.asignar_territorio(territorio_b, &antagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 2), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasBatalla::ordenar_ataque_fuera_de_turno_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &antagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&antagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasBatalla::ordenar_ataque_a_territorio_con_un_ejercito_debe_realizar_batalla(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &antagonista, 1)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(antagonista.recibio_mensaje_de_tipo(TipoDeMensaje::batalla_producida()));
}

void PruebasBatalla::ordenar_ataque_a_territorio_con_mas_de_un_ejercito_debe_preguntar_con_cuantos_defender(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &antagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(antagonista.get_mensaje()->es_de_tipo(TipoDeMensaje::defensa_requerida()));
	
}

void PruebasBatalla::crear_batalla_uno_a_uno_con_empate_debe_ganar_el_defensor(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 2)
		.asignar_territorio(territorio_b, &antagonista, 1)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.usando_estos_dados(3, 3)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	EventoBatallaProducida* mensaje = dynamic_cast<EventoBatallaProducida*>(antagonista.get_mensaje_de_tipo(TipoDeMensaje::batalla_producida()));

	CPPUNIT_ASSERT(mensaje->get_agresores_caidos() == 1);
	CPPUNIT_ASSERT(mensaje->get_defensores_caidos() == 0);
}

void PruebasBatalla::crear_batalla_dos_contra_dos_debe_perder_un_ejercito_cada_uno(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 3)
		.asignar_territorio(territorio_b, &antagonista, 3)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.usando_estos_dados(6, 1, 3, 4)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 2), &protagonista);
	juego->procesar(FabricaDeOrdenes::crear_orden_defender(2), &protagonista);

	EventoBatallaProducida* mensaje = dynamic_cast<EventoBatallaProducida*>(antagonista.get_mensaje_de_tipo(TipoDeMensaje::batalla_producida()));

	CPPUNIT_ASSERT(mensaje->get_agresores_caidos() == 1);
	CPPUNIT_ASSERT(mensaje->get_defensores_caidos() == 1);

}


void PruebasBatalla::crear_batalla_gana_el_defensor_el_territorio_no_debe_ser_conquistado(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 2)
		.asignar_territorio(territorio_b, &antagonista, 1)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.usando_estos_dados(3, 3)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	EventoBatallaProducida* mensaje = dynamic_cast<EventoBatallaProducida*>(antagonista.get_mensaje_de_tipo(TipoDeMensaje::batalla_producida()));

	
	CPPUNIT_ASSERT(!protagonista.get_imperio()->es_propietario_de(territorio_b));
	CPPUNIT_ASSERT(antagonista.get_imperio()->es_propietario_de(territorio_b));
}

void PruebasBatalla::crear_batalla_gana_el_agresor_el_territorio_debe_ser_conquistado(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 2)
		.asignar_territorio(territorio_b, &antagonista, 1)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.usando_estos_dados(5, 3)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_atacar(territorio_a, territorio_b, 1), &protagonista);

	EventoBatallaProducida* mensaje = dynamic_cast<EventoBatallaProducida*>(antagonista.get_mensaje_de_tipo(TipoDeMensaje::batalla_producida()));

	CPPUNIT_ASSERT(protagonista.get_imperio()->es_propietario_de(territorio_a));
	CPPUNIT_ASSERT(!antagonista.get_imperio()->es_propietario_de(territorio_a));
}
