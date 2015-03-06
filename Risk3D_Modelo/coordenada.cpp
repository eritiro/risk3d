#include "coordenada.h"

Coordenada::Coordenada(){}


Coordenada::Coordenada(int x, int y) : x(x), y(y)
{
}

int Coordenada::get_x(){
	return x;
}

int Coordenada::get_y(){
	return y;
}
