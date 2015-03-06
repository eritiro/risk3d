#ifndef SERIALIZADOR_ACTUALIZACION_H_
#define SERIALIZADOR_ACTUALIZACION_H_

#include "serializador_mensaje_especifico.h"
#include "serializador_info_juego.h"

class SerializadorActualizacion : public SerializadorMensajeEspecifico {
	private:
		SerializadorInfoJuego serializador_info_juego;
	
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ACTUALIZACION_H_ */
