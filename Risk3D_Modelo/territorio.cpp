#include "territorio.h"

Territorio::Territorio(int id, string nombre, Coordenada posicion, Continente* continente)
	: Identificable(id), nombre(nombre), posicion(posicion){
	this->continente = continente;
}

Territorio::~Territorio(){
	foreach(IteradorAdyacentes, adyacente, territorios_adyacentes){
		(*adyacente)->eliminar_adyacencia(this);
	}
}

void Territorio::eliminar_adyacencia(const Territorio* territorio){
	foreach(IteradorAdyacentes, adyacente, territorios_adyacentes){
		if((*adyacente)==territorio)
		{
			territorios_adyacentes.erase(adyacente);
			break;
		}
	}
}


string Territorio::get_nombre(){
	return this->nombre;
}

void Territorio::set_nombre(string valor){
	this->nombre = valor;
}

Coordenada Territorio::get_posicion(){
	return this->posicion;
}

void Territorio::set_posicion(Coordenada valor){
	this->posicion = valor;
}

ContenedorAdyacentes& Territorio::get_territorios_adyacentes(){
	return this->territorios_adyacentes;
}

Continente* Territorio::get_continente(){
	return this->continente;
}

void Territorio::set_continente(Continente* continente){
	this->continente = continente;
}


bool Territorio::es_adyacente_a(Territorio* territorio){
	foreach(IteradorAdyacentes, i, territorios_adyacentes)
		if(territorio== *i) return true;
	//else
	return false;
}
