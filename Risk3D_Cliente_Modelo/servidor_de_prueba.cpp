#include "servidor_de_prueba.h"

ServidorDePrueba::ServidorDePrueba(string ruta_mapa){
	LectorDeXml	lector = LectorDeXml::crear_lector_desde_archivo(ruta_mapa);
	SerializadorMapa serializador;
	this->mapa = serializador.deserializar(lector);
	this->info = new InfoJuego(*mapa);
	Imperio* imperio = new Imperio(1, "Pepe", AZUL);
	this->info->get_imperios().push_back(imperio);
	foreach(IteradorTerritorios, i, mapa->get_territorios()){
		imperio->agregar_territorio(*i, 3);
	}

	this->info_enviada = false;
}

ServidorDePrueba::~ServidorDePrueba(){
	delete mapa;
}

void ServidorDePrueba::enviar(Orden* orden){
	delete orden;
}

Mensaje* ServidorDePrueba::get_mensaje(){
	if(!this->info_enviada){
		this->info_enviada =true;
		return FabricaDeMensajes::crear_actualizacion(this->info);
	}
	else
		return 0;
}

InfoJuego* ServidorDePrueba::get_info(){
	return this->info;
}

bool ServidorDePrueba::get_juego_terminado(){
	return false;
}
