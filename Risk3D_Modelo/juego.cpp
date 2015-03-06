#include "juego.h"

#pragma warning(disable:4786)

static Log log("Juego");

Juego::Juego(Mapa& mapa) : info(mapa){
	this->juego_terminado = false;
	this->ambiente = new AmbienteNormal();
	this->estado = new CreandoJuego();
	this->estado->inicializar(this);
	this->ronda = new RondaNormal(*this);
}

Juego::~Juego(){
	delete ambiente;
	delete estado;
	delete ronda;
}

InfoJuego& Juego::get_info(){
	return this->info;
}

AmbienteDeJuego& Juego::get_ambiente(){
	return *this->ambiente;
}

void Juego::set_componente_ambiente(AmbienteDeJuego* valor){
	delete this->ambiente;
	this->ambiente = valor;
}

EstadoDelJuego* Juego::get_estado(){
	return this->estado;
}

void Juego::set_componente_estado(EstadoDelJuego* valor){
	delete this->estado;
	this->estado = valor;
	this->estado->inicializar(this);
}

Ronda& Juego::get_ronda(){
	return *this->ronda;
}

void Juego::set_componente_ronda(Ronda* valor){
	delete this->ronda;
	this->ronda = valor;
}

ContenedorJugadores& Juego::get_jugadores(){
	return this->jugadores;
}

Jugador* Juego::get_creador(){
	return this->jugadores.front();
}

Jugador* Juego::get_jugador_actual(){
	return this->ronda->get_jugador_actual();
}

Jugador* Juego::get_jugador(Imperio* imperio){
	foreach(IteradorJugadores, i, jugadores){
		if(imperio == (*i)->get_imperio())
			return *i;
	}
	// else
	return 0;
}

bool Juego::get_juego_terminado(){
	return this->juego_terminado;
}

void Juego::terminar_juego(){
	this->juego_terminado = true;
}

bool Juego::es_el_turno_de(Jugador* jugador){
	return this->get_jugador_actual() == jugador;
}

void Juego::procesar(Orden* orden, Jugador* jugador){
	// Loguea la orden recibida:
	log.info("El juego recibio la siguiente orden: " + orden->get_descripcion());
	// Procesa y genera el nuevo estado:
	EstadoDelJuego* nuevo_estado = 0;

	try{
		nuevo_estado = this->estado->proximo_estado(*orden, jugador, this);
	}
	catch(ExcepcionDeUsuario& excepcion){
		jugador->recibir_mensaje(FabricaDeMensajes::crear_mensaje_de_error(excepcion));
	}
	catch(ExcepcionDeNegocio& excepcion){
		log.excepcion(excepcion);
	}

	if(nuevo_estado){
		// Elimina el estado anterior:
		delete this->estado;
		// Cambia de estado:
		this->estado = nuevo_estado;
		this->estado->inicializar(this);
		log.info("El estado del juego cambio a \"" + this->estado->get_descripcion() + "\"");
	};

	delete orden;

	foreach(IteradorBots, bot, this->bots){
		(*bot)->jugar();
	}
}

void Juego::notificar_a_todos(string mensaje){
	foreach(IteradorJugadores, i, jugadores){
		(*i)->recibir_mensaje(FabricaDeMensajes::crear_mensaje_de_sistema(mensaje));
	}
	log.info("El juego notifico a todos \"" + mensaje + "\"");
}

void Juego::actualizar(){
	foreach(IteradorJugadores, i, jugadores){
		(*i)->recibir_mensaje(FabricaDeMensajes::crear_actualizacion(&this->info));
	}
	log.info("El juego actualizo a todos los jugadores");
}

void Juego::agregar_bot(JugadorBot* bot){
	this->bots.push_back(bot);
}