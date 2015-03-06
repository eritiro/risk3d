#ifndef TERRITORIO_H_
#define TERRITORIO_H_

#include <string>
#include <vector>
#include "macros.h"
#include "coordenada.h"
#include "identificable.h"

using std::string;

class Continente;
class Territorio;

typedef std::vector<Territorio*> ContenedorAdyacentes;
typedef ContenedorAdyacentes::iterator IteradorAdyacentes;

class Territorio : public Identificable {
	private:
		string nombre;
		Coordenada posicion;
		Continente* continente;
		ContenedorAdyacentes territorios_adyacentes;

		//Lo defino como un objeto no copiable
		Territorio(const Territorio&);
		Territorio& operator= (const Territorio&);

	public:
		Territorio(int id, string nombre, Coordenada posicion, Continente* continente);
		~Territorio();
		//Getters y setters:
		string get_nombre();
		void set_nombre(string valor);
		Coordenada get_posicion();
		void set_posicion(Coordenada valor);
		Continente* get_continente();
		void set_continente(Continente* continente);
		ContenedorAdyacentes& get_territorios_adyacentes();

		bool es_adyacente_a(Territorio * territorio);
		void eliminar_adyacencia(const Territorio* territorio);

};

#endif /* TERRITORIO_H_ */
