#include "serializador_evento_jugador_agregado.h"

void SerializadorEventoJugadorAgregado::serializar(Escritor& escritor, Mensaje& mensaje){
	EventoJugadorAgregado mensaje_especifico = dynamic_cast<EventoJugadorAgregado&>(mensaje);

	escritor.escribir("id_imperio", mensaje_especifico.get_imperio()->get_id());
}

Mensaje* SerializadorEventoJugadorAgregado::deserializar(Lector& lector, InfoJuego& info){
	int id_imperio = lector.leer_int("id_imperio");

	Imperio* imperio = info.get_imperio(id_imperio);

	return FabricaDeMensajes::crear_evento_jugador_agregado(imperio);
}
