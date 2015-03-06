#include "serializador_orden_defender.h"

void SerializadorOrdenDefender::serializar(Escritor& escritor, Orden& orden){
	OrdenDefender orden_especifica = dynamic_cast<OrdenDefender&>(orden);
	escritor.escribir("ejercitos", orden_especifica.get_cantidad_ejercitos());
}

Orden* SerializadorOrdenDefender::deserializar(Lector& lector, InfoJuego& info){
	int ejercitos = lector.leer_int("ejercitos");
	return FabricaDeOrdenes::crear_orden_defender(ejercitos);
}
