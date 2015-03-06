#include "configuracion_mapa.h"
#include "requisito_de_ocupacion.h"

ConfiguracionMapa::ConfiguracionMapa(){
	objetivos_de_destruccion = true;
}

ConfiguracionMapa::~ConfiguracionMapa(){
	foreach(IteradorRequisitos, i, this->requisitos_de_ocupacion)
		delete *i;
}

int ConfiguracionMapa::get_ejercitos_iniciales(int cantidad_participantes){
	switch(cantidad_participantes){
		case 2:
			return 30;
		case 3:
			return 20;
		case 4:
			return 15;
		case 5:
			return 12;
		default:
			return 10;
	}
}

void ConfiguracionMapa::permitir_objetivos_de_destruccion(bool valor){
	this->objetivos_de_destruccion = valor;
}

bool ConfiguracionMapa::hay_objetivos_de_destruccion(){
	return this->objetivos_de_destruccion;
}

ContenedorRequisitos& ConfiguracionMapa::get_requisitos_de_ocupacion(){
	return this->requisitos_de_ocupacion;
}
