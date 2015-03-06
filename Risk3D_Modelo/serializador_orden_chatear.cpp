#include "serializador_orden_chatear.h"

void SerializadorOrdenChatear::serializar(Escritor& escritor, Orden& orden){
	OrdenChatear orden_especifica = dynamic_cast<OrdenChatear&>(orden);
	escritor.escribir("mensaje", orden_especifica.get_mensaje());
}

Orden* SerializadorOrdenChatear::deserializar(Lector& lector, InfoJuego& info){
	string mensaje = lector.leer_string("mensaje");
	return FabricaDeOrdenes::crear_orden_chatear(mensaje);
}
