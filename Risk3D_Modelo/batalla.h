#ifndef BATALLA_H_
#define BATALLA_H_

#pragma warning(disable:4786)

#include <list>
#include "tropa.h"
#include "utilidades_string.h"

using std::list;

typedef list<int> ContenedorDados;

class Juego;

class Batalla{
	private:
		Tropa* tropa_agresora;
		Tropa* tropa_agredida;
		int ejercitos_ataque;
		int ejercitos_defensa;

	public:
		Batalla(Tropa* tropa_agresora, int ejercitos_ataque, Tropa* tropa_agredida);
		Batalla(Tropa* tropa_agresora, int ejercitos_ataque, Tropa* tropa_agredida, int ejercitos_defensa);
		Tropa* get_tropa_agresora();
		Tropa* get_tropa_agredida();
		int get_ejercitos_ataque();
		void set_ejercitos_defensa(int valor);
		void ejecutar(Juego* juego);

};


#endif /* BATALLA_H_ */
