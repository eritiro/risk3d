#ifndef SERIALIZADOR_MENSAJE_ESPECIFICO_H_
#define SERIALIZADOR_MENSAJE_ESPECIFICO_H_

#include "escritor.h"
#include "lector.h"
#include "info_juego.h"
#include "fabrica_de_mensajes.h"

class SerializadorMensajeEspecifico {
	public:
		virtual ~SerializadorMensajeEspecifico(){
		}
		virtual void serializar(Escritor& escritor, Mensaje& mensaje) = 0;
		virtual Mensaje* deserializar(Lector& lector, InfoJuego& info) = 0;
};

#endif /* SERIALIZADOR_MENSAJE_ESPECIFICO_H_ */
