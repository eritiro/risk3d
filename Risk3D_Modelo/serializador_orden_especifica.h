#ifndef SERIALIZADOR_ORDEN_ESPECIFICA_H_
#define SERIALIZADOR_ORDEN_ESPECIFICA_H_

#include "escritor.h"
#include "lector.h"
#include "info_juego.h"
#include "fabrica_de_ordenes.h"

class SerializadorOrdenEspecifica {
	public:
		virtual ~SerializadorOrdenEspecifica(){
		}
		virtual void serializar(Escritor& escritor, Orden& orden) = 0;
		virtual Orden* deserializar(Lector& lector, InfoJuego& info) = 0;
};

#endif /* SERIALIZADOR_ORDEN_H_ */
