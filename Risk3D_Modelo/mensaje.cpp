#include "mensaje.h"

Mensaje::Mensaje(TipoDeMensaje tipo) : tipo(tipo){
}

TipoDeMensaje& Mensaje::get_tipo(){
	return this->tipo;
}

string Mensaje::get_descripcion(){
	return this->tipo.get_clave();
}

Mensaje::~Mensaje(){
}

bool Mensaje::es_de_tipo(TipoDeMensaje& tipo){
	return this->tipo.get_clave() == tipo.get_clave();
}
