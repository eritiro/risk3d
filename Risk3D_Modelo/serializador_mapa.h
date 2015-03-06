#ifndef SERIALIZADOR_MAPA_H_
#define SERIALIZADOR_MAPA_H_

#include "mapa.h"
#include "serializador_requisito_de_ocupacion.h"
#include "escritor.h"
#include "lector.h"

class SerializadorMapa {
	private:

		void agregar_continentes(Escritor& escritor, Mapa& mapa);
		void agregar_territorios(Escritor& escritor, Continente& continente);
		void agregar_adyacencias(Escritor& escritor, Mapa& mapa);
		void agregar_requisitos(Escritor& escritor, Mapa& mapa);

		void leer_continentes(Lector& lector, Mapa& mapa);
		void leer_territorios(Lector& lector, Mapa& mapa, Continente& continente);
		void leer_adyacencias(Lector& lector, Mapa& mapa);
		void leer_requisitos(Lector& lector, Mapa& mapa);

	public:
		void serializar(Escritor& escritor, Mapa& mapa);
		Mapa* deserializar(Lector& lector);
};

#endif /* SERIALIZADOR_MAPA_H_ */
