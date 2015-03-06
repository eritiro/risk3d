#include <cppunit/config/SourcePrefix.h>
#include "pruebas_reagrupacion_de_ejercitos.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PruebasReagrupacionDeEjercitos);

void PruebasReagrupacionDeEjercitos::setUp(){
	//Crea un mapa para las pruebas:
	ConstructorDeMapa constructor(mapa);
	Continente* continente = constructor.agregar_continente("Continente de Pruebas", 1000);
	territorio_a = constructor.agregar_territorio("territorio a", Coordenada(10,10), continente);
	territorio_b = constructor.agregar_territorio("territorio b", Coordenada(20,20), continente);
}


void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_ejercitos_debe_cambiar_de_turno(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &protagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.despues_juega(&antagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(juego->get_jugador_actual() == &antagonista);
}

void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_ejercitos_debe_quitar_ejercitos_desde_el_origen(){
	JugadorDePruebaConMemoria protagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &protagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 2), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_imperio()->get_tropa(territorio_a)->get_ejercitos() == 3);
}

void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_ejercitos_debe_agregar_ejercitos_al_destino(){
	JugadorDePruebaConMemoria protagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &protagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 2), &protagonista);

	CPPUNIT_ASSERT(protagonista.get_imperio()->get_tropa(territorio_b)->get_ejercitos() == 7);
}

void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_ejercitos_desde_territorio_ajeno_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &antagonista, 5)
		.asignar_territorio(territorio_b, &protagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 2), &protagonista);

	CPPUNIT_ASSERT(protagonista.recibio_mensaje_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_ejercitos_hacia_territorio_ajeno_debe_devolver_mensaje_de_error(){
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

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 2), &protagonista);

	CPPUNIT_ASSERT(protagonista.recibio_mensaje_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_mas_ejercitos_que_los_disponibles_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.asignar_territorio(territorio_a, &protagonista, 2)
		.asignar_territorio(territorio_b, &protagonista, 2)
		.en_estado(new Atacando())
		.es_el_turno_de(&protagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 2), &protagonista);

	CPPUNIT_ASSERT(protagonista.recibio_mensaje_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

void PruebasReagrupacionDeEjercitos::ordenar_reagrupar_ejercitos_fuera_de_turno_debe_devolver_mensaje_de_error(){
	JugadorDePruebaConMemoria protagonista;
	JugadorDePruebaConMemoria antagonista;
	Juego* juego = ConstructorDeJuego::crear_juego(mapa)
		.agregar_jugador(&protagonista)
		.agregar_jugador(&antagonista)
		.asignar_territorio(territorio_a, &protagonista, 5)
		.asignar_territorio(territorio_b, &protagonista, 5)
		.en_estado(new Atacando())
		.es_el_turno_de(&antagonista)
		.get_juego();

	juego->procesar(FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(territorio_a, territorio_b, 1), &protagonista);

	CPPUNIT_ASSERT(protagonista.recibio_mensaje_de_tipo(TipoDeMensaje::mensaje_de_error()));
}

