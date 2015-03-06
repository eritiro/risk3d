#include "jugador.h"

Jugador::Jugador(){
	this->imperio = 0;
}

Jugador::~Jugador(){
}

Imperio* Jugador::get_imperio(){
	return this->imperio;
}

void Jugador::set_imperio(Imperio* valor){
	this->imperio = valor;
}

Objetivo* Jugador::get_objetivo(){
	return this->objetivo;
}

void Jugador::set_objetivo(Objetivo* valor){
	this->objetivo = valor;
}

string Jugador::get_nombre_emperador(){
	if(this->imperio != 0)
		return this->imperio->get_nombre_emperador();
	else
		return "Emperador desconocido";
}
