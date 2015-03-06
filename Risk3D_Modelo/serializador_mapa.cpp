#include "serializador_mapa.h"

void SerializadorMapa::serializar(Escritor& escritor, Mapa& mapa){

	escritor.abrir_nodo("mapa");
	escritor.escribir("ruta_textura", mapa.get_ruta_textura());
	this->agregar_continentes(escritor, mapa);
	this->agregar_adyacencias(escritor, mapa);
	this->agregar_requisitos(escritor, mapa);
	escritor.cerrar_nodo();
	
}

Mapa* SerializadorMapa::deserializar(Lector& lector){
	Mapa* mapa = new Mapa();

	lector.visitar_nodo("mapa");
	mapa->set_ruta_textura(lector.leer_string("ruta_textura"));
	this->leer_continentes(lector, *mapa);
	this->leer_adyacencias(lector, *mapa);
	this->leer_requisitos(lector, *mapa);

	lector.salir_nodo();
	return mapa;
}

void SerializadorMapa::agregar_continentes(Escritor& escritor, Mapa& mapa){
	escritor.abrir_nodo("continentes");
	foreach(IteradorContinentes, i, mapa.get_continentes()){
		escritor.abrir_nodo("continente");
		escritor.escribir("id", (*i)->get_id());
		escritor.escribir("nombre", (*i)->get_nombre());
		escritor.escribir("bonus", (*i)->get_bonus());
		this->agregar_territorios(escritor, **i);
		escritor.cerrar_nodo();
	}
	escritor.cerrar_nodo();
}

void SerializadorMapa::agregar_territorios(Escritor& escritor, Continente& continente){
	escritor.abrir_nodo("territorios");
	foreach(IteradorTerritorios, i, continente.get_territorios()){
		escritor.abrir_nodo("territorio");
		escritor.escribir("nombre", (*i)->get_nombre());
		escritor.escribir("id", (*i)->get_id());
		escritor.escribir("x", (*i)->get_posicion().get_x());
		escritor.escribir("y", (*i)->get_posicion().get_y());
		escritor.cerrar_nodo();
	}
	escritor.cerrar_nodo();
}

void SerializadorMapa::agregar_adyacencias(Escritor& escritor, Mapa& mapa){
	escritor.abrir_nodo("adyacencias");
	foreach(IteradorTerritorios, iterador_territorio, mapa.get_territorios()){
		foreach(IteradorAdyacentes, i, (*iterador_territorio)->get_territorios_adyacentes()){
			escritor.abrir_nodo("adyacencia");
			escritor.escribir("id1", (*iterador_territorio)->get_id());
			escritor.escribir("id2", (*i)->get_id());
			escritor.cerrar_nodo();
		}
	}
	escritor.cerrar_nodo();
}

void SerializadorMapa::agregar_requisitos(Escritor& escritor, Mapa& mapa){
	SerializadorRequisitoDeOcupacion serializador_requisito;

	escritor.abrir_nodo("requisitos");
	foreach(IteradorRequisitos, iterador_requisito, mapa.get_configuracion().get_requisitos_de_ocupacion()){
		serializador_requisito.serializar(escritor, **iterador_requisito);
	}
	escritor.cerrar_nodo();
}

void SerializadorMapa::leer_continentes(Lector& lector, Mapa& mapa){
	lector.visitar_nodo("continentes");
	foreach(IteradorNodos, i, lector.get_nodos("continente")){
		lector.visitar_nodo(*i);
		int id = lector.leer_int("id");
		string nombre = lector.leer_string("nombre");
		int bonus = lector.leer_int("bonus");
		Continente* continente = new Continente(id, nombre, bonus);
		mapa.get_continentes().push_back(continente);
		this->leer_territorios(lector, mapa, *continente);
		lector.salir_nodo();
	}
	lector.salir_nodo();
}

void SerializadorMapa::leer_territorios(Lector& lector, Mapa& mapa, Continente& continente){
	lector.visitar_nodo("territorios");
	foreach(IteradorNodos, i, lector.get_nodos("territorio")){
		lector.visitar_nodo(*i);
		string nombre = lector.leer_string("nombre");
		int id = lector.leer_int("id");
		int x = lector.leer_int("x");
		int y = lector.leer_int("y");
		Territorio* territorio = new Territorio(id, nombre, Coordenada(x,y), &continente);
		continente.get_territorios().push_back(territorio);
		mapa.get_territorios().push_back(territorio);
		lector.salir_nodo();
	}
	lector.salir_nodo();
}

void SerializadorMapa::leer_adyacencias(Lector& lector, Mapa& mapa){
	lector.visitar_nodo("adyacencias");
	foreach(IteradorNodos, i, lector.get_nodos("adyacencia")){
		lector.visitar_nodo(*i);
		Territorio* t1 = mapa.get_territorio(lector.leer_int("id1"));
		Territorio* t2 = mapa.get_territorio(lector.leer_int("id2"));
		t1->get_territorios_adyacentes().push_back(t2);
		lector.salir_nodo();
	}
	lector.salir_nodo();
}

void SerializadorMapa::leer_requisitos(Lector& lector, Mapa& mapa){
	SerializadorRequisitoDeOcupacion serializador_requisito;

	lector.visitar_nodo("requisitos");
	foreach(IteradorNodos, i, lector.get_nodos("requisito")){
		RequisitoDeOcupacion* requisito = serializador_requisito.deserializar(lector, mapa, *i);
		mapa.get_configuracion().get_requisitos_de_ocupacion().push_back(requisito);
	}
	lector.salir_nodo();
}
