#include "asignando_inicialmente_tropas.h"
#include "reforzando_territorios.h"

AsignandoInicialmenteTropas::AsignandoInicialmenteTropas() 
	: EstadoDelJuego("Asignando inicialmente tropas"){
}

void AsignandoInicialmenteTropas::inicializar(Juego* juego){
	Imperio* imperio_actual = juego->get_jugador_actual()->get_imperio();
	int cantidad_jugadores = juego->get_jugadores().size();
	int ejercitos = juego->get_info().get_mapa().get_configuracion().get_ejercitos_iniciales(cantidad_jugadores);
	imperio_actual->set_ejercitos_disponibles(ejercitos);
	juego->actualizar();
}

EstadoDelJuego* AsignandoInicialmenteTropas::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){
	OrdenTerminarTurno* ordenTerminarTurno = dynamic_cast<OrdenTerminarTurno*>(&orden);
	OrdenReforzarTerritorio* ordenReforzarTerritorio = dynamic_cast<OrdenReforzarTerritorio*>(&orden);
	if(ordenTerminarTurno){
		ordenTerminarTurno->ejecutar(juego, jugador);
		//Si es el turno del primer jugador de nuevo...
		if(juego->es_el_turno_de(juego->get_ronda().get_primer_jugador())){
			//Cambia de estado
			juego->notificar_a_todos("Ya se puede atacar!!!");
			return new ReforzandoTerritorios();
		}
		else{
			return new AsignandoInicialmenteTropas();
		}
	}
	else if (ordenReforzarTerritorio){
		ordenReforzarTerritorio->ejecutar(juego, jugador);
		return 0;
	}
	else
		return EstadoDelJuego::proximo_estado(orden, jugador, juego);
}
