#include "ciclo_de_vida.h"

CicloDeVida::~CicloDeVida(){
	foreach(IteradorTranferibles, i, objetos_asociados){
		delete *i;
	}
}

void CicloDeVida::agregar_objeto_tranferible(Tranferible* objeto){
	this->objetos_asociados.push_back(objeto);
}
