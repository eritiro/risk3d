#include "continente.h"

Continente::Continente(int id, string nombre, int bonus) : Identificable(id), nombre(nombre), bonus(bonus){
}

Continente::~Continente(){
	foreach(IteradorTerritorios, i, territorios)
		delete *i;
}

ContenedorTerritorios& Continente::get_territorios(){
	return this->territorios;
}

string Continente::get_nombre(){
	return this->nombre;
}

int Continente::get_bonus(){
	return this->bonus;
}


void Continente::set_nombre(string nombre){
	this->nombre = nombre;
}


void Continente::set_bonus(int bonus){
	this->bonus = bonus;
}