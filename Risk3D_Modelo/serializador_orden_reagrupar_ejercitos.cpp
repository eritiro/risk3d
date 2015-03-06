#include "serializador_orden_reagrupar_ejercitos.h"

void SerializadorOrdenReagruparEjercitos::serializar(Escritor& escritor, Orden& orden){
	OrdenReagruparEjercitos orden_especifica = dynamic_cast<OrdenReagruparEjercitos&>(orden);
	escritor.escribir("origen", orden_especifica.get_origen()->get_id());
	escritor.escribir("destino", orden_especifica.get_destino()->get_id());
	escritor.escribir("ejercitos", orden_especifica.get_cantidad_ejercitos());
}

Orden* SerializadorOrdenReagruparEjercitos::deserializar(Lector& lector, InfoJuego& info){
	int id_origen = lector.leer_int("origen");
	int id_destino = lector.leer_int("destino");
	int ejercitos = lector.leer_int("ejercitos");

	Territorio* origen = info.get_mapa().get_territorio(id_origen);
	Territorio* destino = info.get_mapa().get_territorio(id_destino);
	return FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(origen, destino, ejercitos);
}
