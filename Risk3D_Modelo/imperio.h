#ifndef IMPERIO_H_
#define IMPERIO_H_

#include <string>
#include <list>
#include "macros.h"
#include "color_imperio.h"
#include "tropa.h"

using std::string;
using std::list;

#define MAXIMO_DE_IMPERIOS 6

typedef std::list<Tropa*> ContenedorTropas;
typedef ContenedorTropas::iterator IteradorTropas;

class Imperio : public Identificable {
	private:
		string nombre_emperador;
		ColorImperio color;
		list<Tropa*> tropas;
		int ejercitos_disponibles;
	public:
		Imperio(int id, string nombre_emperador, ColorImperio color);
		Imperio(int id, string nombre_emperador, ColorImperio color, int ejercitos_disponibles);
		~Imperio();

		string get_nombre_emperador();
		ColorImperio get_color();
		ContenedorTropas& get_tropas();

		// Obtiene la tropa del respectivo territorio.
		Tropa* get_tropa(Territorio* territorio);

		int get_ejercitos_disponibles();
		void set_ejercitos_disponibles(int valor);
		//El valor que se desea agregar puede ser positivo o negativo
		void agregar_ejercitos_disponibles(int valor);

		bool es_propietario_de(Territorio* territorio);
		void agregar_territorio(Territorio* territorio, int ejercitos);
		void abandonar_territorio(Territorio* territorio);
};


#endif /* IMPERIO_H_ */
