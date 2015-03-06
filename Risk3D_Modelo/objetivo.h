#ifndef OBJETIVO_H_
#define OBJETIVO_H_

#include <vector>
#include "info_juego.h"

class Objetivo;

typedef std::vector<Objetivo*> ContenedorObjetivos;
typedef ContenedorObjetivos::iterator IteradorObjetivos;

class Objetivo {
	protected:
		static Objetivo objetivo_global;
		Objetivo();
	public:
		// devuelve verdadero si el objetivo del juego fue cumplido
		virtual bool fue_cumplido(Imperio* imperio, InfoJuego* info);

		// devuelve verdadero si el objetivo del juego es un objetivo valido para el imperio
		virtual bool es_valido(Imperio* imperio, InfoJuego* info);

		// devuelve la descripcion del objetivo
		virtual string get_descripcion();

		// devuelve una instancia del objetivo global
		static Objetivo* get_objetivo_global();
};


#endif /* OBJETIVO_H_ */
