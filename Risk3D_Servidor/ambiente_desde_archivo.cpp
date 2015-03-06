#include "ambiente_desde_archivo.h"

AmbienteDesdeArchivo::AmbienteDesdeArchivo(string nombre_archivo) : archivo(nombre_archivo.c_str()) {
	if(!archivo) throw ExcepcionRisk3D("No se puede abrir el archivo de dados");
}

int AmbienteDesdeArchivo::generar_valor_aleatorio(int minimo, int maximo){
	int valor;
	archivo >> valor;
	return valor;
}
