#ifndef CONTINENTE_H_
#define CONTINENTE_H_

#include <vector>
#include "macros.h"
#include "territorio.h"

using std::vector;

class Continente;

typedef std::vector<Continente*> ContenedorContinentes;
typedef ContenedorContinentes::iterator IteradorContinentes;

typedef std::vector<Territorio*> ContenedorTerritorios;
typedef ContenedorTerritorios::iterator IteradorTerritorios;

class Continente : public Identificable {
	private:
		ContenedorTerritorios territorios;
		int bonus;
		string nombre;

		//Lo defino como un objeto no copiable
		Continente(const Continente&);
		Continente& operator= (const Continente&);

	public:
		Continente(int id, string nombre, int bonus);
		~Continente();
		ContenedorTerritorios& get_territorios();
		string get_nombre();
		int get_bonus();
		void set_nombre(string nombre);
		void set_bonus(int bonus);
};


#endif /* CONTINENTE_H_ */
