#ifndef SERIALIZADOR_ORDEN_DEFENDER_H_
#define SERIALIZADOR_ORDEN_DEFENDER_H_

#include "serializador_orden_especifica.h"
#include "orden_defender.h"

class SerializadorOrdenDefender : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_DEFENDER_H_ */
