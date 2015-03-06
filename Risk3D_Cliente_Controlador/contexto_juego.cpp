#include "contexto_juego.h"

ContextoJuego ContextoJuego::CrearContexto(){
	return ContextoJuego();
}

ContextoJuego::ContextoJuego() {
}

ContextoJuego::ContextoJuego(ContextoJuego const &){
}

bool ContextoJuego::get_es_creador_del_juego(){
	return this->es_creador_del_juego;
}

void ContextoJuego::set_es_creador_del_juego(bool valor){
	this->es_creador_del_juego = valor;
}

HiloEjecucion* ContextoJuego::get_hilo_servidor(){
	return hilo_servidor;
}

void ContextoJuego::set_hilo_servidor(HiloEjecucion* valor){
	hilo_servidor = valor;
}

Servidor* ContextoJuego::get_servidor(){
	return servidor;
}

void ContextoJuego::set_servidor(Servidor* valor){
	servidor = valor;
}

int ContextoJuego::get_id_imperio(){
	return this->id_imperio;
}

void ContextoJuego::set_id_imperio(int valor){
	this->id_imperio = valor;
}
