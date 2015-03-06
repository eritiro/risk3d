#ifndef AMBIENTE_NORMAL_H_
#define AMBIENTE_NORMAL_H_

#include <cstdlib>
#include <ctime>
#include "ambiente_de_juego.h"

class AmbienteNormal : public AmbienteDeJuego {
	public:
		AmbienteNormal();
		int generar_valor_aleatorio(int minimo, int maximo);
};


#endif /* AMBIENTE_NORMAL_H_ */
