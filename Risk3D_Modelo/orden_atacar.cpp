#include "orden_atacar.h"

OrdenAtacar::OrdenAtacar(Territorio* origen, Territorio* destino, int cantidad_ejercitos)
	: Orden(TipoDeOrden::atacar()), origen(origen), destino(destino), cantidad_ejercitos(cantidad_ejercitos){
}

Territorio* OrdenAtacar::get_origen(){
	return this->origen;
}

Territorio* OrdenAtacar::get_destino(){
	return this->destino;
}

int OrdenAtacar::get_cantidad_ejercitos(){
	return this->cantidad_ejercitos;
}
