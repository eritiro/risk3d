#include "orden_defender.h"

OrdenDefender::OrdenDefender(int cantidad_ejercitos) 
	: Orden(TipoDeOrden::defender()), cantidad_ejercitos(cantidad_ejercitos){
}

int OrdenDefender::get_cantidad_ejercitos(){
	return this->cantidad_ejercitos;
}