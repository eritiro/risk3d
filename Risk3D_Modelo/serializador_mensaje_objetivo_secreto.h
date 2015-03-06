#ifndef SERIALIZADOR_MENSAJE_OBJETIVO_SECRETO_H_
#define SERIALIZADOR_MENSAJE_OBJETIVO_SECRETO_H_

#include "serializador_mensaje_especifico.h"
#include "serializador_requisito_de_ocupacion.h"

class SerializadorMensajeObjetivoSecreto : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_MENSAJE_OBJETIVO_SECRETO_H_ */
