#ifndef REQUISITO_DE_OCUPACION_H_
#define REQUISITO_DE_OCUPACION_H_

#pragma warning(disable:4786)
#include <map>
#include "continente.h"


typedef std::map<int,int> TablaContinentes;
typedef TablaContinentes::iterator IteradorTablaContinentes;

class Mapa;

class RequisitoDeOcupacion : public Identificable {
	private:
		Mapa& mapa;
		TablaContinentes territorios_a_conquistar_por_continente;

	public:
		RequisitoDeOcupacion(int id, Mapa& mapa);
		int get_territorios_a_conquistar_por_continente(Continente* continente);

		void set_requerimiento(Continente* continente, int cantidad_territorios);
		ContenedorContinentes get_continentes_requeridos();
};


#endif /* REQUISITO_DE_OCUPACION_H_ */
