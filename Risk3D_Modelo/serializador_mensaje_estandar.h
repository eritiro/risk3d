#ifndef SERIALIZADOR_MENSAJE_ESTANDAR_H_
#define SERIALIZADOR_MENSAJE_ESTANDAR_H_

#include "serializador_mensaje_especifico.h"

template<class T> class SerializadorMensajeEstandar : public SerializadorMensajeEspecifico {
	public:
		void serializar(Escritor& escritor, Mensaje& mensaje){
		}

		Mensaje* deserializar(Lector& lector, InfoJuego& info){
			return new T();
		}
};

#endif /* SERIALIZADOR_MENSAJE_ESTANDAR_H_ */
