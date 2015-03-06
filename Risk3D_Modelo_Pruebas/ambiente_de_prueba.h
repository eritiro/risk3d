#ifndef AMBIENTE_DE_PRUEBA_H_
#define AMBIENTE_DE_PRUEBA_H_

#include <vector>
#include "ambiente_de_juego.h"

using std::vector;

typedef vector<int> ContenedorInts;
typedef ContenedorInts::iterator IteradorInts;

class AmbienteDePrueba : public AmbienteDeJuego {
	private:
		ContenedorInts datos_de_entrada;
		IteradorInts iterador;
	public:
		AmbienteDePrueba(int datos_de_entrada[]);
		int generar_valor_aleatorio(int minimo, int maximo);
};


#endif /* AMBIENTE_DE_PRUEBA_H_ */
