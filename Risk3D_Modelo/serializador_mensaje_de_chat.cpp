#include "serializador_mensaje_de_chat.h"

void SerializadorMensajeDeChat::serializar(Escritor& escritor, Mensaje& mensaje){
	MensajeDeChat mensaje_especifico = dynamic_cast<MensajeDeChat&>(mensaje);
	escritor.escribir("imperio", mensaje_especifico.get_imperio()->get_id());
	escritor.escribir("contenido", mensaje_especifico.get_mensaje());
}

Mensaje* SerializadorMensajeDeChat::deserializar(Lector& lector, InfoJuego& info){
	int id_imperio = lector.leer_int("imperio");
	Imperio* imperio = info.get_imperio(id_imperio);

	string contenido = lector.leer_string("contenido");

	return FabricaDeMensajes::crear_mensaje_de_chat(imperio, contenido);
}
