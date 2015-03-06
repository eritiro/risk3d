#ifndef SERIALIZADOR_ORDEN_ESTANDAR_H_
#define SERIALIZADOR_ORDEN_ESTANDAR_H_

#include "serializador_orden_especifica.h"

template<class T> class SerializadorOrdenEstandar : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden){
		}

		Orden* deserializar(Lector& lector, InfoJuego& info){
			return new T();
		}
};

#endif /* SERIALIZADOR_ORDEN_ESTANDAR_H_ */
