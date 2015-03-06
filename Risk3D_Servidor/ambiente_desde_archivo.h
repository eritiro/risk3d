#ifndef AMBIENTE_DESDE_ARCHIVO_H_
#define AMBIENTE_DESDE_ARCHIVO_H_

#include <iostream>
#include <fstream>
#include "ambiente_de_juego.h"
#include "excepcion_risk3d.h"

using std::ifstream;
using std::string;

class AmbienteDesdeArchivo : public AmbienteDeJuego {
	private:
		ifstream archivo;
	public:
		AmbienteDesdeArchivo(string nombre_archivo);
		int generar_valor_aleatorio(int minimo, int maximo);
};


#endif /* AMBIENTE_DESDE_ARCHIVO_H_ */
 