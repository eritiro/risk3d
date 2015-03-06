#include "serializador_evento_batalla_producida.h"

void SerializadorEventoBatallaProducida::serializar(Escritor& escritor, Mensaje& mensaje){
	EventoBatallaProducida mensaje_especifico = dynamic_cast<EventoBatallaProducida&>(mensaje);

	escritor.escribir("agresor", mensaje_especifico.get_agresor()->get_id());
	escritor.escribir("agredido", mensaje_especifico.get_agredido()->get_id());
	escritor.escribir("agresores_caidos", mensaje_especifico.get_agresores_caidos());
	escritor.escribir("defensores_caidos", mensaje_especifico.get_defensores_caidos());
}

Mensaje* SerializadorEventoBatallaProducida::deserializar(Lector& lector, InfoJuego& info){
	int id_agresor = lector.leer_int("agresor");
	int id_agredido = lector.leer_int("agredido");
	int agresores_caidos = lector.leer_int("agresores_caidos");
	int defensores_caidos = lector.leer_int("defensores_caidos");

	Territorio* agresor = info.get_mapa().get_territorio(id_agresor);
	Territorio* agredido = info.get_mapa().get_territorio(id_agredido);

	return FabricaDeMensajes::crear_evento_batalla_producida(agresor, agresores_caidos, agredido, defensores_caidos);
}
