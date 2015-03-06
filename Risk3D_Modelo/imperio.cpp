#include "imperio.h"

Imperio::Imperio(int id, string nombre_emperador, ColorImperio color) 
	: Identificable(id), nombre_emperador(nombre_emperador), color(color), ejercitos_disponibles(0) {
}

Imperio::Imperio(int id, string nombre_emperador, ColorImperio color, int ejercitos_disponibles) 
	: Identificable(id), nombre_emperador(nombre_emperador), color(color), ejercitos_disponibles(ejercitos_disponibles) {
}

Imperio::~Imperio(){
	foreach(IteradorTropas, i, tropas)
		delete *i;
}

ContenedorTropas& Imperio::get_tropas(){
	return this->tropas;
}

bool Imperio::es_propietario_de(Territorio* territorio){
	return this->get_tropa(territorio) != 0;
}

void Imperio::agregar_territorio(Territorio* territorio, int ejercitos){
	tropas.push_back(new Tropa(this, territorio, ejercitos));
}

void Imperio::abandonar_territorio(Territorio* territorio){
	foreach(IteradorTropas, i, tropas){
		if((*i)->get_territorio() == territorio){
			delete *i;
			tropas.erase(i);
			return;
		}	
	}
}

ColorImperio Imperio::get_color(){
	return this->color;
}

string Imperio::get_nombre_emperador(){
	return this->nombre_emperador;
}

int Imperio::get_ejercitos_disponibles(){
	return this->ejercitos_disponibles;
}

void Imperio::set_ejercitos_disponibles(int valor){
	this->ejercitos_disponibles = valor;
}

void Imperio::agregar_ejercitos_disponibles(int valor){
	this->ejercitos_disponibles += valor;
}

Tropa* Imperio::get_tropa(Territorio* territorio){
	foreach(IteradorTropas, i, tropas){
		if((*i)->get_territorio() == territorio)
			return *i;
	}
	//else
	return 0;
}
