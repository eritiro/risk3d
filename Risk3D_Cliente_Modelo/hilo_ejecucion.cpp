#include "hilo_ejecucion.h"

HiloEjecucion::HiloEjecucion(string comando) : comando(comando){
}

void HiloEjecucion::ejecutar(){
	system(comando.c_str());
}
