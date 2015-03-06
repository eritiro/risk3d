#include "serializador_evento_juego_terminado.h"

void SerializadorEventoJuegoTerminado::serializar(Escritor& escritor, Mensaje& mensaje){
	EventoJuegoTerminado mensaje_especifico = dynamic_cast<EventoJuegoTerminado&>(mensaje);

	escritor.escribir("id_imperio", mensaje_especifico.get_imperio_ganador()->get_id());
	escritor.escribir("objetivo", mensaje_especifico.get_objetivo());
}

Mensaje* SerializadorEventoJuegoTerminado::deserializar(Lector& lector, InfoJuego& info){
	int id_imperio = lector.leer_int("id_imperio");
	string objetivo = lector.leer_string("objetivo");

	Imperio* imperio = info.get_imperio(id_imperio);

	return FabricaDeMensajes::crear_evento_juego_terminado(imperio, objetivo);
}
