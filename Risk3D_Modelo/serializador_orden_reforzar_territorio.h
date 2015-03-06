#ifndef SERIALIZADOR_ORDEN_REFORZAR_TERRITORIO_H_
#define SERIALIZADOR_ORDEN_REFORZAR_TERRITORIO_H_

#include "serializador_orden_especifica.h"
#include "orden_reagrupar_ejercitos.h"

class SerializadorOrdenReforzarTerritorio : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_REFORZAR_TERRITORIO_H_ */
