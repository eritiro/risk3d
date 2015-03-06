#ifndef CONSTRUCTOR_DE_MAPA_H_
#define CONSTRUCTOR_DE_MAPA_H_

#include "mapa.h"
#include "excepcion_de_negocio.h"
#include "requisito_de_ocupacion.h"

#include "log.h"

using std::string;

// Se encarga de construir un mapa manteniendo sus invariantes entre los 
// distintos elementos que lo componen.
// Usar unicamente metodos de esta clase para la construcción de un mapa.
// En los metodos que se necesita pasar como parametro un territorio o un 
// continente estos pueden ser extraidos por medio del mapa con get_mapa().
class ConstructorDeMapa {
	private:
		Mapa& mapa;

		void quitar_territorio_de_continente(Territorio* territorio);

	public:
		ConstructorDeMapa(Mapa& mapa_a_construir);
		
		Continente* agregar_continente(string nombre, int bonus);
		void modificar_continente(Continente* continente, string nuevo_nombre, int nuevo_bonus);
		void eliminar_continente(Continente* continente);

		Territorio* agregar_territorio(string nombre, Coordenada posicion, Continente* continente);
		void modificar_territorio(Territorio* territorio, string nombre, Continente* continente);
		void eliminar_territorio(Territorio* territorio);

		void agregar_adyacencia(Territorio* t1, Territorio* t2);
		void eliminar_adyacencia(Territorio* t1, Territorio* t2);

		RequisitoDeOcupacion* agregar_requisito();
		void eliminar_requisito(RequisitoDeOcupacion* requisito);
		
		Mapa& get_mapa();
};


#endif /* CONSTRUCTOR_DE_MAPA_H_ */
