#include "estado_belico.h"
#include "reforzando_territorios.h"

EstadoBelico::EstadoBelico(string descripcion) : EstadoDelJuego(descripcion){
}

EstadoDelJuego* EstadoBelico::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){
	
	OrdenTerminarTurno* ordenTerminarTurno = dynamic_cast<OrdenTerminarTurno*>(&orden);
	OrdenAtacar* ordenAtacar = dynamic_cast<OrdenAtacar*>(&orden);
	OrdenReagruparEjercitos* ordenReagrupar = dynamic_cast<OrdenReagruparEjercitos*>(&orden);

	if(ordenTerminarTurno){
		ordenTerminarTurno->ejecutar(juego, jugador);
		return new ReforzandoTerritorios();
	}
	else if(ordenAtacar){
		return atacar(ordenAtacar, jugador, juego);
	}
	else if(ordenReagrupar)
		return reagrupar(ordenReagrupar, jugador, juego);
	else 
		return EstadoDelJuego::proximo_estado(orden, jugador, juego);
}

EstadoDelJuego* EstadoBelico::atacar(OrdenAtacar* ordenAtacar, Jugador* jugador, Juego* juego){
	int cantidad_ejercitos = ordenAtacar->get_cantidad_ejercitos();
	Territorio* origen = ordenAtacar->get_origen();
	Territorio* destino = ordenAtacar->get_destino();

	// Valida que sea el turno del jugador
	if(!juego->es_el_turno_de(jugador))
		throw ExcepcionOrdenInvalida();
	// Valida que el territorio origen pertenezca al imperio
	if(!jugador->get_imperio()->es_propietario_de(origen))
		throw ExcepcionDeUsuario("No puede atacar desde un territorio que no pertenece a su imperio.");
	// Valida que el territorio destino no pertenezca al imperio
	if(jugador->get_imperio()->es_propietario_de(destino))
		throw ExcepcionDeUsuario("No se puede atacar a un territorio propio.");
	// Valida que los territorios sean adyacentes.
	if(!origen->es_adyacente_a(destino))
		throw ExcepcionDeUsuario("No se pueden realizar batallas entre territorios no adyacentes.");
	// Valida que la cantidad de ejercitos no supere el limite.
	if(cantidad_ejercitos > 3)
		throw ExcepcionDeUsuario("No se puede atacar con mas de 3 ejercitos.");

	Tropa* tropa_agresora = jugador->get_imperio()->get_tropa(origen);
	// Valida que haya suficientes ejercitos para realizar el ataque.
	if(jugador->get_imperio()->get_tropa(origen)->get_ejercitos() < cantidad_ejercitos + 1)
		throw ExcepcionDeUsuario("No tiene suficientes ejercitos disponibles para realizar el ataque.");

	Imperio* imperio_agredido = juego->get_info().get_propietario(destino);
	Tropa* tropa_agredida = imperio_agredido->get_tropa(destino);
	if(tropa_agredida->get_ejercitos() > 1){
		Batalla batalla(tropa_agresora, cantidad_ejercitos, tropa_agredida);
		return new EsperandoDefensa(batalla);
	}
	else{
		Batalla batalla(tropa_agresora, cantidad_ejercitos, tropa_agredida, 1);
		batalla.ejecutar(juego);
		if(!this->hay_un_ganador(juego))
			return this->proximo_estado_guerra(juego);
		else
			return new FinDelJuego();
	}
}

EstadoDelJuego* EstadoBelico::reagrupar(OrdenReagruparEjercitos* ordenReagrupar, Jugador* jugador, Juego* juego){
	int cantidad_ejercitos = ordenReagrupar->get_cantidad_ejercitos();
	Territorio* origen = ordenReagrupar->get_origen();
	Territorio* destino = ordenReagrupar->get_destino();

	// Valida que sea el turno del jugador.
	if(!juego->es_el_turno_de(jugador))
		throw ExcepcionOrdenInvalida();

	// Valida que el territorio origen pertenezca al imperio.
	if(!jugador->get_imperio()->es_propietario_de(origen))
		throw ExcepcionDeUsuario("No puede reagrupar ejercitos desde un territorio que no pertenece a su imperio.");

	// Valida que el territorio destino pertenezca al imperio.
	if(!jugador->get_imperio()->es_propietario_de(destino))
		throw ExcepcionDeUsuario("No puede reagrupar ejercitos hacia un territorio que no pertenece a su imperio.");

	Tropa* tropa_origen = jugador->get_imperio()->get_tropa(origen);
	Tropa* tropa_destino = jugador->get_imperio()->get_tropa(destino);

	// Valida que haya suficientes ejercitos para reagrupar.
	if(jugador->get_imperio()->get_tropa(origen)->get_ejercitos() < cantidad_ejercitos + 1)
		throw ExcepcionDeUsuario("No tiene suficientes ejercitos disponibles para reagrupar.");

	tropa_origen->agregar_ejercitos(-cantidad_ejercitos);
	tropa_destino->agregar_ejercitos(cantidad_ejercitos);

	juego->get_ronda().finalizar_turno();
	juego->notificar_a_todos("Es el turno de " + juego->get_jugador_actual()->get_nombre_emperador());

	return new ReforzandoTerritorios();
}
