#include "ambiente_de_prueba.h"

AmbienteDePrueba::AmbienteDePrueba(int datos_de_entrada[]){
	for(int i = 0; i < sizeof(datos_de_entrada); i++)
		this->datos_de_entrada.push_back(datos_de_entrada[i]);
	
	iterador = this->datos_de_entrada.begin();
}

int AmbienteDePrueba::generar_valor_aleatorio(int minimo, int maximo){
	int resultado = *iterador;
	iterador++;
	return resultado;
}