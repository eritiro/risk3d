#ifndef SERIALIZADOR_ORDEN_ATACAR_H_
#define SERIALIZADOR_ORDEN_ATACAR_H_

#include "serializador_orden_especifica.h"
#include "orden_atacar.h"

class SerializadorOrdenAtacar : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_ATACAR_H_ */
