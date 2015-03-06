#include "ambiente_normal.h"

AmbienteNormal::AmbienteNormal(){
	srand(time(NULL));
}

int AmbienteNormal::generar_valor_aleatorio(int minimo, int maximo){
	return (rand() % (maximo - minimo + 1)) + minimo;
}

