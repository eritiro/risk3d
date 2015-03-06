#include "orden_reagrupar_ejercitos.h"

OrdenReagruparEjercitos::OrdenReagruparEjercitos(Territorio* origen, Territorio* destino, int cantidad_ejercitos)
	: Orden(TipoDeOrden::reagrupar_ejercitos()), origen(origen), destino(destino), cantidad_ejercitos(cantidad_ejercitos){
}

Territorio* OrdenReagruparEjercitos::get_origen(){
	return this->origen;
}

Territorio* OrdenReagruparEjercitos::get_destino(){
	return this->destino;
}

int OrdenReagruparEjercitos::get_cantidad_ejercitos(){
	return this->cantidad_ejercitos;
}
