#ifndef SERIALIZADOR_ORDEN_REAGRUPAR_EJERCITOS_H_
#define SERIALIZADOR_ORDEN_REAGRUPAR_EJERCITOS_H_

#include "serializador_orden_especifica.h"
#include "orden_reagrupar_ejercitos.h"

class SerializadorOrdenReagruparEjercitos : public SerializadorOrdenEspecifica {
	public:
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_REAGRUPAR_EJERCITOS_H_ */
