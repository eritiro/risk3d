#include "serializador_info_juego.h"

void SerializadorInfoJuego::serializar(Escritor& escritor, InfoJuego& info){
	escritor.abrir_nodo("info");

	escritor.abrir_nodo("imperios");
	foreach(IteradorImperios, i, info.get_imperios())
		this->serializar_imperio(escritor, **i);
	escritor.cerrar_nodo();

	escritor.cerrar_nodo();
}

InfoJuego* SerializadorInfoJuego::deserializar(Lector& lector, Mapa& mapa){
	InfoJuego* info = new InfoJuego(mapa);
	lector.visitar_nodo("info");

	lector.visitar_nodo("imperios");
	foreach(IteradorNodos, i, lector.get_nodos("imperio"))
		this->deserializar_imperio(lector, *i, info);
	lector.salir_nodo();	

	lector.salir_nodo();
	return info;
}

void SerializadorInfoJuego::serializar_imperio(Escritor& escritor, Imperio& imperio){
	escritor.abrir_nodo("imperio");
	escritor.escribir("id", imperio.get_id());
	escritor.escribir("nombre", imperio.get_nombre_emperador());
	escritor.escribir("color", imperio.get_color());
	escritor.escribir("ejercitos", imperio.get_ejercitos_disponibles());
	
	escritor.abrir_nodo("tropas");
	foreach(IteradorTropas, i, imperio.get_tropas())
		this->serializar_tropa(escritor, **i);
	escritor.cerrar_nodo();
	
	escritor.cerrar_nodo();
}

void SerializadorInfoJuego::serializar_tropa(Escritor& escritor, Tropa& tropa){
	escritor.abrir_nodo("tropa");
	escritor.escribir("territorio", tropa.get_territorio()->get_id());
	escritor.escribir("ejercitos", tropa.get_ejercitos());
	escritor.cerrar_nodo();
}

void SerializadorInfoJuego::deserializar_imperio(Lector& lector, Nodo* nodo, InfoJuego* info){
	lector.visitar_nodo(nodo);
	
	int id = lector.leer_int("id");
	string nombre = lector.leer_string("nombre");
	ColorImperio color = (ColorImperio)lector.leer_int("color");
	int ejercitos = lector.leer_int("ejercitos");

	Imperio* imperio = new Imperio(id, nombre, color, ejercitos);

	lector.visitar_nodo("tropas");
	foreach(IteradorNodos, i, lector.get_nodos("tropa"))
		this->deserializar_tropa(lector, *i, info, imperio);
	lector.salir_nodo();

	info->get_imperios().push_back(imperio);

	lector.salir_nodo();
}

void SerializadorInfoJuego::deserializar_tropa(Lector& lector, Nodo* nodo, InfoJuego* info, Imperio* imperio){
	lector.visitar_nodo(nodo);

	int id_territorio = lector.leer_int("territorio");
	int ejercitos = lector.leer_int("ejercitos");

	Territorio* territorio = info->get_mapa().get_territorio(id_territorio);
	imperio->get_tropas().push_back(new Tropa(imperio, territorio, ejercitos));

	lector.salir_nodo();
}
