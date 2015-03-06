#ifndef SERIALIZADOR_ORDEN_CHATEAR_H_
#define SERIALIZADOR_ORDEN_CHATEAR_H_

#include "serializador_orden_especifica.h"
#include "orden_chatear.h"

class SerializadorOrdenChatear : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_CHATEAR_H_ */
