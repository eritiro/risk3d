#ifndef SERIALIZADOR_ORDEN_AGREGAR_JUGADOR_H_
#define SERIALIZADOR_ORDEN_AGREGAR_JUGADOR_H_

#include "serializador_orden_especifica.h"
#include "orden_agregar_jugador.h"

class SerializadorOrdenAgregarJugador : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_AGREGAR_JUGADOR_H_ */
