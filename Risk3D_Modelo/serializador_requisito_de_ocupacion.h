#ifndef SERIALIZADOR_REQUISITO_DE_OCUPACION_H_
#define SERIALIZADOR_REQUISITO_DE_OCUPACION_H_

#include "requisito_de_ocupacion.h"
#include "mapa.h"
#include "escritor.h"
#include "lector.h"

class SerializadorRequisitoDeOcupacion {
	private:
		RequisitoDeOcupacion* hacer_deserializado(Lector& lector, Mapa& mapa);
	public:
		void serializar(Escritor& escritor, RequisitoDeOcupacion& requisito);
		RequisitoDeOcupacion* deserializar(Lector& lector, Mapa& mapa);
		RequisitoDeOcupacion* deserializar(Lector& lector, Mapa& mapa, Nodo* nodo);
};

#endif /* SERIALIZADOR_REQUISITO_DE_OCUPACION_H_ */
