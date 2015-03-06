#ifndef SERIALIZADOR_MENSAJE_DE_ERROR_H_
#define SERIALIZADOR_MENSAJE_DE_ERROR_H_

#include "serializador_mensaje_especifico.h"

class SerializadorMensajeDeError : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_MENSAJE_DE_ERROR_H_ */
