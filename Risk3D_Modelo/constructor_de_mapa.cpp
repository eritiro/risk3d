#include "constructor_de_mapa.h"

static Log log("ConstructorDeMapa");


ConstructorDeMapa::ConstructorDeMapa(Mapa& mapa_a_construir) : mapa(mapa_a_construir){
}

Mapa& ConstructorDeMapa::get_mapa(){
	return this->mapa;
}


/************************************** EDICION DE CONTINENTES **************************************/


Continente* ConstructorDeMapa::agregar_continente(string nombre, int bonus){
	//Comprueba que el nombre no este vacio
	if(nombre == "")
		throw ExcepcionDeNegocio("El nombre no puede estar vacio.");

	//Comprueba que el nombre sea unico
	foreach(IteradorContinentes, i, mapa.get_continentes()){
		if(nombre == (*i)->get_nombre())
			throw ExcepcionDeNegocio("Ya existe un continente con el mismo nombre.");
	}

	mapa.get_continentes().push_back(new Continente(generar_id(mapa.get_continentes()), nombre, bonus));
	log.info("Continente agregado: " + nombre);
	return mapa.get_continentes().back();
}


void ConstructorDeMapa::modificar_continente(Continente* continente, string nuevo_nombre, int nuevo_bonus){
	//Comprueba que el nombre no este vacio
	if(nuevo_nombre == "")
		throw ExcepcionDeNegocio("El nombre no puede estar vacio.");

	//Comprueba que el nombre sea unico
	foreach(IteradorContinentes, i, mapa.get_continentes()){
		if((nuevo_nombre == (*i)->get_nombre()) && (continente != *i))
			throw ExcepcionDeNegocio("Ya existe un continente con el mismo nombre.");
	}

	continente->set_nombre(nuevo_nombre);
	continente->set_bonus(nuevo_bonus);
}


void ConstructorDeMapa::eliminar_continente(Continente* continente){

	IteradorTerritorios j = continente->get_territorios().begin();
	while (j != continente->get_territorios().end()){
		this->eliminar_territorio(*j);
		j = continente->get_territorios().begin();
	}

	foreach(IteradorContinentes, i, mapa.get_continentes()){
		if(*i == continente)
		{
			mapa.get_continentes().erase(i);
			break;
		}
	}
	delete continente;
}


/************************************** EDICION DE TERRITORIOS **************************************/


Territorio* ConstructorDeMapa::agregar_territorio(string nombre, Coordenada posicion, Continente* continente){
	//Comprueba que el nombre no este vacio
	if(nombre == "")
		throw ExcepcionDeNegocio("El nombre no puede estar vacio.");

	//Comprueba que el territorio tenga un continente
	if(continente == 0)
		throw ExcepcionDeNegocio("El territorio requiere pertenecer a un continente.");
	
	//Comprueba que el nombre sea unico
	foreach(IteradorTerritorios, i, mapa.get_territorios()){
		if(nombre == (*i)->get_nombre())
			throw ExcepcionDeNegocio("Ya existe un territorio con el mismo nombre.");
	}

	Territorio* territorio = new Territorio(generar_id(mapa.get_territorios()), nombre, posicion, continente);
	mapa.get_territorios().push_back(territorio);
	continente->get_territorios().push_back(territorio);
	log.info("Territorio agregado: " + nombre);
	return territorio;
}


void ConstructorDeMapa::modificar_territorio(Territorio* territorio, string nombre, Continente* continente){
	//Comprueba que el nombre no este vacio
	if(nombre == "")
		throw ExcepcionDeNegocio("El nombre no puede estar vacio.");

	//Comprueba que el territorio tenga un continente
	if(continente == 0)
		throw ExcepcionDeNegocio("El territorio requiere pertenecer a un continente.");
	
	//Comprueba que el nombre sea unico
	foreach(IteradorTerritorios, i, mapa.get_territorios()){
		if((nombre == (*i)->get_nombre()) && (*i != territorio))
			throw ExcepcionDeNegocio("Ya existe un territorio con el mismo nombre.");
	}

	this->quitar_territorio_de_continente(territorio);
	territorio->set_nombre(nombre);
	continente->get_territorios().push_back(territorio);
	territorio->set_continente(continente);
}


void ConstructorDeMapa::eliminar_territorio(Territorio* territorio){
	Continente* continente = territorio->get_continente();

	foreach(IteradorTerritorios, i, continente->get_territorios()){
		if((*i) == territorio){
			continente->get_territorios().erase(i);
			break;
		}
	}

	foreach(IteradorTerritorios, territorio_en_mapa, mapa.get_territorios()){
		if( (*territorio_en_mapa) == territorio){
			mapa.get_territorios().erase(territorio_en_mapa);
			break;
		}
	}
	delete territorio;
}


/************************************** EDICION DE ADYACENCIAS **************************************/


void ConstructorDeMapa::agregar_adyacencia(Territorio* t1, Territorio* t2){
	// Comprueba que los dos territorios no sean el mismo.
	if (t1 == t2) 
		throw ExcepcionDeNegocio("Un territorio no puede ser adyacente a si mismo.");
	
	if (!t1->es_adyacente_a(t2)) {
		t1->get_territorios_adyacentes().push_back(t2);
		t2->get_territorios_adyacentes().push_back(t1);
		log.info("Adyacencia agregada: " + t1->get_nombre() + " - " + t2->get_nombre());
	}
	else {
		log.alerta("Se intento volver a agregar la adyacencia: " + t1->get_nombre() + " - " + t2->get_nombre());
	}
}


void ConstructorDeMapa::eliminar_adyacencia(Territorio* t1, Territorio* t2){
	// Comprueba que la adyacencia exista.
	if (!t1->es_adyacente_a(t2)) 
		throw ExcepcionDeNegocio("No se puede eliminar una adyacencia inexistente.");

	t1->eliminar_adyacencia(t2);
	t2->eliminar_adyacencia(t1);
	log.info("Adyacencia eliminada: " + t1->get_nombre() + " - " + t2->get_nombre());
}


/****************************************** REQUERIMIENTOS ******************************************/


RequisitoDeOcupacion* ConstructorDeMapa::agregar_requisito(){
	ContenedorRequisitos* requisitos = &this->mapa.get_configuracion().get_requisitos_de_ocupacion();
	RequisitoDeOcupacion* requisito = new RequisitoDeOcupacion(generar_id(*requisitos), this->mapa);
	requisitos->push_back(requisito);
	return requisito;
}


void ConstructorDeMapa::eliminar_requisito(RequisitoDeOcupacion* requisito){
	ContenedorRequisitos* requisitos = &this->mapa.get_configuracion().get_requisitos_de_ocupacion();
	foreach(IteradorRequisitos, i, *requisitos){
		if((*i)==requisito){
			requisitos->erase(i);
			delete requisito;
			return;
		}

	}	
	// else
	throw ExcepcionDeNegocio("El requerimiento no pertenece al mapa.");
}


/********************************************** OTROS ***********************************************/


void ConstructorDeMapa::quitar_territorio_de_continente(Territorio* territorio){
	Continente* continente = territorio->get_continente();
	foreach(IteradorTerritorios, j, continente->get_territorios()){
		if (*j == territorio){
			continente->get_territorios().erase(j);
			return;
		}
	}
}

