#include "tropa.h"

Tropa::Tropa(Imperio* imperio, Territorio* territorio, int ejercitos) {
	this->imperio = imperio;
	this->territorio = territorio;
	this->ejercitos = ejercitos;
}

Territorio* Tropa::get_territorio(){
	return this->territorio;
}

Imperio* Tropa::get_imperio(){
	return this->imperio;
}

int Tropa::get_ejercitos(){
	return this->ejercitos;
}

void Tropa::set_ejercitos(int valor){
	this->ejercitos = valor;
}

void Tropa::agregar_ejercitos(int valor){
	this->ejercitos += valor;
}