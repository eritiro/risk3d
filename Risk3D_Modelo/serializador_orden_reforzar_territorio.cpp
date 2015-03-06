#include "serializador_orden_reforzar_territorio.h"

void SerializadorOrdenReforzarTerritorio::serializar(Escritor& escritor, Orden& orden){
	OrdenReforzarTerritorio orden_especifica = dynamic_cast<OrdenReforzarTerritorio&>(orden);
	escritor.escribir("territorio", orden_especifica.get_territorio()->get_id());
	escritor.escribir("ejercitos", orden_especifica.get_cantidad_ejercitos());
}

Orden* SerializadorOrdenReforzarTerritorio::deserializar(Lector& lector, InfoJuego& info){
	int id_territorio = lector.leer_int("territorio");
	int ejercitos = lector.leer_int("ejercitos");

	Territorio* territorio = info.get_mapa().get_territorio(id_territorio);
	return FabricaDeOrdenes::crear_orden_reforzar_territorio(territorio, ejercitos);
}
