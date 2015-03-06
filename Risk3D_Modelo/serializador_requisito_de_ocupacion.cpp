#include "serializador_requisito_de_ocupacion.h"

void SerializadorRequisitoDeOcupacion::serializar(Escritor& escritor, RequisitoDeOcupacion& requisito){
	escritor.abrir_nodo("requisito");

	escritor.escribir("id", requisito.get_id());

	escritor.abrir_nodo("continentes");
	ContenedorContinentes continentes_requeridos = requisito.get_continentes_requeridos();
	foreach(IteradorContinentes, i, continentes_requeridos){
		escritor.abrir_nodo("continente");
		escritor.escribir("id", (*i)->get_id());
		escritor.escribir("cantidad", requisito.get_territorios_a_conquistar_por_continente(*i));
		escritor.cerrar_nodo();
	}
	escritor.cerrar_nodo();

	escritor.cerrar_nodo();
}

RequisitoDeOcupacion* SerializadorRequisitoDeOcupacion::deserializar(Lector& lector, Mapa& mapa){
	lector.visitar_nodo("requisito");

	RequisitoDeOcupacion* requisito = this->hacer_deserializado(lector, mapa);
	
	lector.salir_nodo();

	return requisito;
}

RequisitoDeOcupacion* SerializadorRequisitoDeOcupacion::deserializar(Lector& lector, Mapa& mapa, Nodo* nodo){
	lector.visitar_nodo(nodo);

	RequisitoDeOcupacion* requisito = this->hacer_deserializado(lector, mapa);
	
	lector.salir_nodo();

	return requisito;
}


RequisitoDeOcupacion* SerializadorRequisitoDeOcupacion::hacer_deserializado(Lector& lector, Mapa& mapa){
	ContenedorRequisitos requisitos = mapa.get_configuracion().get_requisitos_de_ocupacion();

	int id_requisito = lector.leer_int("id");

	RequisitoDeOcupacion* requisito = new RequisitoDeOcupacion(id_requisito, mapa);

	lector.visitar_nodo("continentes");

	foreach(IteradorNodos, i, lector.get_nodos("continente")){
		lector.visitar_nodo(*i);

		int id = lector.leer_int("id");
		int cantidad = lector.leer_int("cantidad");
		Continente* continente = mapa.get_continente(id);
		requisito->set_requerimiento(continente, cantidad);
		
		lector.salir_nodo();
	}
	
	lector.salir_nodo();	

	return requisito;
}