#pragma warning(disable:4786)

#include "objetivo_de_ocupacion.h"
#include "requisito_de_ocupacion.h"

ObjetivoDeOcupacion::ObjetivoDeOcupacion(RequisitoDeOcupacion* requisito){
	this->requisito = requisito;
}

bool ObjetivoDeOcupacion::cumple_el_objetivo_del_continente(Imperio* imperio, Continente* continente){
	int territorios_esperados = this->requisito->get_territorios_a_conquistar_por_continente(continente);
	int territorios_ocupados = 0;
	foreach(IteradorTerritorios, territorio, continente->get_territorios()){
		if(imperio->es_propietario_de(*territorio))
			territorios_ocupados++;
	}
	return territorios_ocupados >= territorios_esperados;
}

bool ObjetivoDeOcupacion::fue_cumplido(Imperio* imperio, InfoJuego* info){

	bool cumple_el_objetivo_de_ocupacion = true;

	foreach(IteradorContinentes, continente, info->get_mapa().get_continentes()){
		if(!this->cumple_el_objetivo_del_continente(imperio, *continente))
			cumple_el_objetivo_de_ocupacion = false;
	}

	if(cumple_el_objetivo_de_ocupacion)
		// se fija si se cumplio el objetivo de ocupacion
		return true;
	else
		// se fija si se cumplio el objetivo global
		return Objetivo::fue_cumplido(imperio, info);
}

string ObjetivoDeOcupacion::get_descripcion(){
	string descripcion = "Ocupar ";

	ContenedorContinentes continentes = this->requisito->get_continentes_requeridos();


	int cantidad_continentes = continentes.size();
	int posicion = 0;

	foreach(IteradorContinentes, i, continentes){

		// logica para calcular si debe ir un "y" una coma o nada al final de cada parte del objetivo:
		posicion++;
		string concatenador;
		if(posicion == cantidad_continentes)
			concatenador = "";
		else if(posicion == cantidad_continentes -1)
			concatenador = " y\n";
		else
			concatenador = ",\n";


		int cantidad = this->requisito->get_territorios_a_conquistar_por_continente(*i);
		if(cantidad == (*i)->get_territorios().size())
			descripcion += "todo " + (*i)->get_nombre() + concatenador;
		else if (cantidad == 1)
			descripcion += "un territorio de " + (*i)->get_nombre() + concatenador;
		else
			descripcion += UtilidadesString::int_a_string(cantidad) + " territorios de " + (*i)->get_nombre() + concatenador;
	}

	descripcion += ".";

	return descripcion;
}
