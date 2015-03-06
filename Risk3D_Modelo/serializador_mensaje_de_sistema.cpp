#include "serializador_mensaje_de_sistema.h"

void SerializadorMensajeDeSistema::serializar(Escritor& escritor, Mensaje& mensaje){
	MensajeDeSistema mensaje_especifico = dynamic_cast<MensajeDeSistema&>(mensaje);
	escritor.escribir("contenido", mensaje_especifico.get_mensaje());
}

Mensaje* SerializadorMensajeDeSistema::deserializar(Lector& lector, InfoJuego& info){
	string contenido = lector.leer_string("contenido");
	return FabricaDeMensajes::crear_mensaje_de_sistema(contenido);
}
