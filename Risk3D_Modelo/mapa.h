#ifndef MAPA_H_
#define MAPA_H_

/* Aclaracion: este warning surge a raiz de la inclusion de "vector" en este archivo. 
Hasta el momento se desconoce la causar. Investigar. */
#pragma warning(disable:4786)

#include <string>
#include "macros.h"
#include "territorio.h"
#include "continente.h"
#include "configuracion_mapa.h"

using std::string;


class Mapa {
	private:
		ContenedorTerritorios territorios;
		ContenedorContinentes continentes;
		ConfiguracionMapa configuracion;
		string ruta_textura;

	public:
		~Mapa();
		ContenedorTerritorios& get_territorios();
		ContenedorContinentes& get_continentes();
		ConfiguracionMapa& get_configuracion();

		string get_ruta_textura();
		void set_ruta_textura(string valor);

		Territorio* get_territorio(int id);
		Continente* get_continente(int id);
		Continente* get_continente(string nombre_continente);

};


#endif /* MAPA_H_ */
