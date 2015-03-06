#include "objetivo_de_destruccion.h"

ObjetivoDeDestruccion::ObjetivoDeDestruccion(Imperio* imperio_a_eliminar){
	this->imperio_a_eliminar = imperio_a_eliminar;
}

bool ObjetivoDeDestruccion::fue_cumplido(Imperio* imperio, InfoJuego* info){

	bool cumple_el_objetivo_de_eliminar = true;

	foreach(IteradorTerritorios, territorio, info->get_mapa().get_territorios()){
		if(this->imperio_a_eliminar->es_propietario_de(*territorio))
			cumple_el_objetivo_de_eliminar = false;
	}

	if(cumple_el_objetivo_de_eliminar)
		// se fija si se cumplio el objetivo de ocupacion
		return true;
	else
		// se fija si se cumplio el objetivo global
		return Objetivo::fue_cumplido(imperio, info);
}

bool ObjetivoDeDestruccion::es_valido(Imperio* imperio, InfoJuego* info){
	// devuelve verdadero si el imperio no debe eliminarse a si mismo.
	return this->imperio_a_eliminar != imperio;
}

string ObjetivoDeDestruccion::get_descripcion(){
	return "Destruir todas las tropas de " + imperio_a_eliminar->get_nombre_emperador() + ".";
}