#ifndef SERIALIZADOR_MENSAJE_DE_CHAT_H_
#define SERIALIZADOR_MENSAJE_DE_CHAT_H_

#include "serializador_mensaje_especifico.h"

class SerializadorMensajeDeChat : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_MENSAJE_DE_CHAT_H_ */
