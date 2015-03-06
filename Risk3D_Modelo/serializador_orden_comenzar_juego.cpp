#include "serializador_orden_comenzar_juego.h"

void SerializadorOrdenComenzarJuego::serializar(Escritor& escritor, Orden& orden){
}

Orden* SerializadorOrdenComenzarJuego::deserializar(Lector& lector, InfoJuego& info){
	return new OrdenComenzarJuego();
}
