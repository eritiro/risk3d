#ifndef SERIALIZADOR_EVENTO_JUGADOR_AGREGADO_H_
#define SERIALIZADOR_EVENTO_JUGADOR_AGREGADO_H_

#include "serializador_mensaje_especifico.h"

class SerializadorEventoJugadorAgregado : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_EVENTO_JUGADOR_AGREGADO_H_ */
