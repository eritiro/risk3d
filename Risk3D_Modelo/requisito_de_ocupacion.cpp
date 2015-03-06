#include "requisito_de_ocupacion.h"
#include "mapa.h"

RequisitoDeOcupacion::RequisitoDeOcupacion(int id, Mapa& mapa) : Identificable(id), mapa(mapa){
}

int RequisitoDeOcupacion::get_territorios_a_conquistar_por_continente(Continente* continente){
	return this->territorios_a_conquistar_por_continente[continente->get_id()];
}

void RequisitoDeOcupacion::set_requerimiento(Continente* continente, int cantidad_territorios){
	this->territorios_a_conquistar_por_continente[continente->get_id()] = cantidad_territorios;
}

ContenedorContinentes RequisitoDeOcupacion::get_continentes_requeridos(){
	ContenedorContinentes continentes;
	foreach(IteradorTablaContinentes, par, this->territorios_a_conquistar_por_continente){
		int id_continente = par->first;
		int cantidad = par->second;
		if(cantidad > 0)
			continentes.push_back(this->mapa.get_continente(id_continente));
	}
	return continentes;
}