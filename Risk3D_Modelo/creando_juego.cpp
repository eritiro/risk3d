#include "creando_juego.h"

#pragma warning(disable:4786)

static Log log("CreandoJuego");

CreandoJuego::CreandoJuego() : EstadoDelJuego("Creando juego"){
}

EstadoDelJuego* CreandoJuego::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){
	
	if(orden.es_de_tipo(TipoDeOrden::agregar_jugador())){
		OrdenAgregarJugador* ordenAgregarJugador = dynamic_cast<OrdenAgregarJugador*>(&orden);
		string nombre = ordenAgregarJugador->get_nombre();
		ColorImperio color = ordenAgregarJugador->get_color();
		bool es_creador = ordenAgregarJugador->es_creador_del_juego();
		this->agregar_jugador(nombre, color, jugador, juego, es_creador);
		return 0;
	}
	else if(orden.es_de_tipo(TipoDeOrden::comenzar_el_juego())){
		this->crear_juego(juego, jugador);
		return new AsignandoInicialmenteTropas();
	}
	else
		return EstadoDelJuego::proximo_estado(orden, jugador, juego);
}

void CreandoJuego::crear_juego(Juego* juego, Jugador* jugador){

	if(juego->get_creador() != jugador)
		throw ExcepcionDeUsuario("Solo el creador del juego lo puede inicializar");

	if(juego->get_jugadores().size() < 2)
		throw ExcepcionDeUsuario("Debe haber por lo menos dos jugadores para poder inicializar el juego");

	juego->get_ronda().ordenar_turnos();
	
	// Reparte los territorios
	RepartidorDeTerritorios repartidor_de_territorios;
	repartidor_de_territorios.repartir_territorios(juego);

	// Reparte los objetivos
	RepartidorDeObjetivos repartidor_de_objetivos(juego->get_info().get_mapa().get_configuracion(), juego->get_ambiente(), juego->get_info());
	repartidor_de_objetivos.repartir_objetivos(juego->get_jugadores());


	juego->get_ronda().empezar_ronda();
	juego->actualizar();

	foreach(IteradorJugadores, j, juego->get_jugadores()){
		(*j)->recibir_mensaje(FabricaDeMensajes::crear_evento_juego_iniciado());
		(*j)->recibir_mensaje(FabricaDeMensajes::crear_mensaje_objetivo_secreto((*j)->get_objetivo()));

	}

	juego->notificar_a_todos("En esta ronda solo podran reforzar sus tropas.");

	juego->notificar_a_todos("Es el turno de " + juego->get_jugador_actual()->get_nombre_emperador());
}


void CreandoJuego::agregar_jugador(string nombre, ColorImperio color, Jugador* jugador, Juego* juego, bool es_creador){

	if((juego->get_jugadores().size() == 0) && !es_creador)
		throw ExcepcionDeUsuario("El primer jugador que se une al juego debe ser el creador.");

	// Para cada jugador del juego:
	foreach(IteradorJugadores, i, juego->get_jugadores()){
		// Si el jugador ya estaba en el juego lanza una excepcion.
		if((*i) == jugador){
			throw ExcepcionDeUsuario("El jugador ya se habia agregado al juego previamente.");
		}

		// Si ya existia un imperio con el mismo nombre lanza una excepcion.
		if((*i)->get_nombre_emperador() == nombre){
			throw ExcepcionDeUsuario("Ya existe un emperador con el mismo nombre.");
		}

		// Si ya existia un imperio con el mismo color lanza una excepcion.
		if((*i)->get_imperio()->get_color() == color){
			throw ExcepcionDeUsuario("Ya existe un imperio con el mismo color.");
		}
	}

	Imperio* imperio = new Imperio(generar_id(juego->get_info().get_imperios()), nombre, color);
	jugador->set_imperio(imperio);
	juego->get_info().get_imperios().push_back(imperio);
	juego->get_jugadores().push_back(jugador);

	log.info("Se agrego exitosamente al jugador.");
	juego->actualizar();
	jugador->recibir_mensaje(FabricaDeMensajes::crear_evento_jugador_agregado(imperio));
	juego->notificar_a_todos("Se agrego el emperador " + jugador->get_nombre_emperador());
}
