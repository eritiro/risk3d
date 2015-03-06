#include "mapa.h"

ContenedorTerritorios& Mapa::get_territorios(){
	return this->territorios;
}

ContenedorContinentes& Mapa::get_continentes(){
	return this->continentes;
}

ConfiguracionMapa& Mapa::get_configuracion(){
	return this->configuracion;
}

string Mapa::get_ruta_textura(){
	return this->ruta_textura;
}

void Mapa::set_ruta_textura(string valor){
	this->ruta_textura = valor;
}

Territorio* Mapa::get_territorio(int id){
	foreach(IteradorTerritorios, i, territorios)
	{
		if((*i)->get_id() == id) 
			return *i;
	}
	//else
	return 0;
}

Continente* Mapa::get_continente(int id){
	foreach(IteradorContinentes, i, this->continentes){
		if (id == (*i)->get_id()){
			return (*i);
		}
	}
	//else
	return 0;
}

Continente* Mapa::get_continente(string nombre_continente){
	foreach(IteradorContinentes, i, this->continentes){
		if (nombre_continente == (*i)->get_nombre()){
			return (*i);
		}
	}
	//else
	return 0;
}


Mapa::~Mapa(){
	foreach(IteradorContinentes, i, continentes)
		delete *i;
}
