#include "orden.h"

Orden::Orden(TipoDeOrden tipo) : tipo(tipo){
}

Orden::~Orden(){
}

TipoDeOrden& Orden::get_tipo(){
	return this->tipo;
}

string Orden::get_descripcion(){
	return this->tipo.get_clave();
}

bool Orden::es_de_tipo(TipoDeOrden& tipo){
	return this->tipo.get_clave() == tipo.get_clave();
}
