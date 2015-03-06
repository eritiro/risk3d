#ifndef OBJETIVO_DE_DESTRUCCION_H_
#define OBJETIVO_DE_DESTRUCCION_H_

#include "objetivo.h"

class ObjetivoDeDestruccion : public Objetivo {
	private:
		Imperio* imperio_a_eliminar;

	public:
		ObjetivoDeDestruccion(Imperio* imperio_a_eliminar);
		bool fue_cumplido(Imperio* imperio, InfoJuego* info);
		bool es_valido(Imperio* imperio, InfoJuego* info);
		string get_descripcion();
};


#endif /* OBJETIVO_DE_DESTRUCCION_H_ */
