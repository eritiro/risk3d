#ifndef OBJETIVO_DE_OCUPACION_H_
#define OBJETIVO_DE_OCUPACION_H_

#include "utilidades_string.h"
#include "objetivo.h"

class ObjetivoDeOcupacion : public Objetivo {
	private:
		RequisitoDeOcupacion* requisito;

		bool cumple_el_objetivo_del_continente(Imperio* imperio, Continente* continente);
	public:
		ObjetivoDeOcupacion(RequisitoDeOcupacion* requisito);
		bool fue_cumplido(Imperio* imperio, InfoJuego* info);
		string get_descripcion();
};


#endif /* OBJETIVO_DE_OCUPACION_H_ */
