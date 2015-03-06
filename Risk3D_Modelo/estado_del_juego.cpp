#pragma warning(disable:4786)

#include "estado_del_juego.h"
#include "juego.h"
#include "jugador_bot_simple.h"

static Log log("EstadoDelJuego");

EstadoDelJuego::EstadoDelJuego(string descripcion) : descripcion(descripcion){
}

string EstadoDelJuego::get_descripcion(){
	return this->descripcion;
}

EstadoDelJuego::~EstadoDelJuego(){
}

void EstadoDelJuego::inicializar(Juego* juego){
	// por defecto no hace nada.
}

EstadoDelJuego* EstadoDelJuego::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){
	if(orden.es_de_tipo(TipoDeOrden::quitar_jugador())){
		this->quitar_jugador(jugador, juego);
		return 0;
	} 
	else if(orden.es_de_tipo(TipoDeOrden::cancelar_el_juego())){
		if(juego->get_jugadores().size() == 0)
			juego->terminar_juego();
		else if(jugador == juego->get_creador())
			juego->terminar_juego();
		else
			throw ExcepcionDeUsuario("Solo el jugador que creo el juego puede cancelarlo.");
		return 0;
	}
	else if(orden.es_de_tipo(TipoDeOrden::chatear())){
		OrdenChatear* orden_chatear = dynamic_cast<OrdenChatear*>(&orden);
		Imperio* imperio = jugador->get_imperio();
		string mensaje = orden_chatear->get_mensaje();
		foreach(IteradorJugadores, i, juego->get_jugadores()){
			(*i)->recibir_mensaje(FabricaDeMensajes::crear_mensaje_de_chat(imperio, mensaje));
		}

		return 0;
	}
	else
		throw ExcepcionOrdenInvalida();
}

bool EstadoDelJuego::hay_un_ganador(Juego* juego){
	foreach(IteradorJugadores, jugador, juego->get_jugadores()){
		Objetivo* objetivo = (*jugador)->get_objetivo();
		if(objetivo->fue_cumplido((*jugador)->get_imperio(), &juego->get_info())){
			return true;
		}
	}
	// else
	return false;
}

void EstadoDelJuego::quitar_jugador(Jugador* jugador, Juego* juego){
	foreach(IteradorJugadores, i, juego->get_jugadores()){
		if(*i == jugador){

			JugadorBotSimple* bot = new JugadorBotSimple(*juego);
			bot->set_imperio(jugador->get_imperio());

			// Se reemplaza al jugador anterior por un bot
			juego->get_jugadores().erase(i);
			juego->get_jugadores().push_back(bot);

			// Le damos al juego la responsabilidad de liberar la memoria del bot
			bot->asociar_al_ciclo_de_vida_de(*juego);

			// Agregamos el bot al juego
			juego->agregar_bot(bot);



			log.info(jugador->get_nombre_emperador() + " abandono el juego.");
			juego->notificar_a_todos(jugador->get_nombre_emperador() + " abandono el juego.");

			break;
		}
	}
}
