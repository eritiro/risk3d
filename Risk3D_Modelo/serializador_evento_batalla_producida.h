#ifndef SERIALIZADOR_EVENTO_BATALLA_PRODUCIDA_H_
#define SERIALIZADOR_EVENTO_BATALLA_PRODUCIDA_H_

#pragma warning(disable:4786)

#include "serializador_mensaje_especifico.h"

class SerializadorEventoBatallaProducida : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_EVENTO_BATALLA_PRODUCIDA_H_ */
