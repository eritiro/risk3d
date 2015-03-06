#include "objetivo.h"

Objetivo Objetivo::objetivo_global;

Objetivo::Objetivo(){
}

//el objetivo global es que un jugador posea todos los territorios
bool Objetivo::fue_cumplido(Imperio* imperio, InfoJuego* info){
	foreach(IteradorTerritorios, territorio, info->get_mapa().get_territorios()){
		if(!imperio->es_propietario_de(*territorio))
			return false;
	}
	// else
	return true;
}

bool Objetivo::es_valido(Imperio* imperio, InfoJuego* info){
	// devuelve verdadero si el objetivo aun no fue cumplido
	return !this->fue_cumplido(imperio, info);
}

string Objetivo::get_descripcion(){
	return "Ocupar todos los paises y eliminar a todos los imperios.";
}

Objetivo* Objetivo::get_objetivo_global(){
	return &objetivo_global;
}
