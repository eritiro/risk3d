#ifndef SERIALIZADOR_EVENTO_JUEGO_TERMINADO_H_
#define SERIALIZADOR_EVENTO_JUEGO_TERMINADO_H_

#include "serializador_mensaje_especifico.h"

class SerializadorEventoJuegoTerminado : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_EVENTO_JUEGO_TERMINADO_H_ */
