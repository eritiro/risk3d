#pragma warning(disable:4786)

#include "serializador_defensa_requerida.h"

void SerializadorDefensaRequerida::serializar(Escritor& escritor, Mensaje& mensaje){
	DefensaRequerida mensaje_especifico = dynamic_cast<DefensaRequerida&>(mensaje);

	escritor.escribir("territorio_agresor", mensaje_especifico.get_territorio_agresor()->get_id());
	escritor.escribir("territorio_agredido", mensaje_especifico.get_territorio_agredido()->get_id());
	escritor.escribir("ejercitos_ataque", mensaje_especifico.get_ejercitos_ataque());
}

Mensaje* SerializadorDefensaRequerida::deserializar(Lector& lector, InfoJuego& info){
	int id_agresor = lector.leer_int("territorio_agresor");
	int id_agredido = lector.leer_int("territorio_agredido");
	int ejercitos_ataque = lector.leer_int("ejercitos_ataque");
	
	Territorio* agresor = info.get_mapa().get_territorio(id_agresor);
	Territorio* agredido = info.get_mapa().get_territorio(id_agredido);

	return FabricaDeMensajes::crear_defensa_requerida(agresor, agredido, ejercitos_ataque);
}
