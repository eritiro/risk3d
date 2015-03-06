#ifndef SERIALIZADOR_DEFENSA_REQUERIDA_H_
#define SERIALIZADOR_DEFENSA_REQUERIDA_H_

#include "serializador_mensaje_especifico.h"

class SerializadorDefensaRequerida : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_DEFENSA_REQUERIDA_H_ */
