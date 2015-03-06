#ifndef CONFIGURACION_INICIAL_MAPA_H_
#define CONFIGURACION_INICIAL_MAPA_H_

#pragma warning(disable:4786)

#include <vector>
#include "macros.h"

class RequisitoDeOcupacion;

typedef std::vector<RequisitoDeOcupacion*> ContenedorRequisitos;
typedef ContenedorRequisitos::iterator IteradorRequisitos;

class ConfiguracionMapa {
	private:
		bool objetivos_de_destruccion;
		ContenedorRequisitos requisitos_de_ocupacion;
	public:
		ConfiguracionMapa();
		~ConfiguracionMapa();

		void permitir_objetivos_de_destruccion(bool valor);
		int get_ejercitos_iniciales(int cantidad_participantes);

		ContenedorRequisitos& get_requisitos_de_ocupacion();
		bool hay_objetivos_de_destruccion();

};


#endif /* CONFIGURACION_INICIAL_MAPA_H_ */
