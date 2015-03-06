#pragma warning(disable:4786)

#include "esperando_defensa.h"
#include "atacando.h"

EsperandoDefensa::EsperandoDefensa(Batalla batalla)
	: batalla(batalla), EstadoDelJuego("Esperando defensa") {
}

void EsperandoDefensa::inicializar(Juego* juego){
	Tropa* tropa_agredida = batalla.get_tropa_agredida();
	Imperio* imperio_agredido = tropa_agredida->get_imperio();
	Jugador* jugador_agredido = juego->get_jugador(imperio_agredido);

	juego->notificar_a_todos("Esperando que " + jugador_agredido->get_nombre_emperador() + " responda al ataque.");
	this->preguntar_defensa(jugador_agredido);
}


EstadoDelJuego* EsperandoDefensa::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){

	OrdenDefender* ordenDefender= dynamic_cast<OrdenDefender*>(&orden);

	if(ordenDefender){
		if(juego->get_jugador(batalla.get_tropa_agredida()->get_imperio()) != jugador)
			throw ExcepcionOrdenInvalida();

		if(ordenDefender->get_cantidad_ejercitos() < 1){
			jugador->recibir_mensaje(FabricaDeMensajes::crear_mensaje_de_error("No puede defenderse con menos de un ejercito."));
			this->preguntar_defensa(jugador);			
			return 0;
		}

		if(ordenDefender->get_cantidad_ejercitos() > 2){
			jugador->recibir_mensaje(FabricaDeMensajes::crear_mensaje_de_error("No puede defenderse con mas de 2 ejercitos."));
			this->preguntar_defensa(jugador);
			return 0;
		}

		batalla.set_ejercitos_defensa(ordenDefender->get_cantidad_ejercitos());
		batalla.ejecutar(juego);
		if(!this->hay_un_ganador(juego))
			return new Atacando();
		else
			return new FinDelJuego();
	}
	else 
		return EstadoDelJuego::proximo_estado(orden, jugador, juego);
}

void EsperandoDefensa::preguntar_defensa(Jugador* jugador_agredido){
	int ejercitos_ataque = batalla.get_ejercitos_ataque();
	Territorio* territorio_agresor = batalla.get_tropa_agresora()->get_territorio();
	Territorio* territorio_agredido = batalla.get_tropa_agredida()->get_territorio();
	jugador_agredido->recibir_mensaje(FabricaDeMensajes::crear_defensa_requerida(territorio_agresor, territorio_agredido, ejercitos_ataque));
}
