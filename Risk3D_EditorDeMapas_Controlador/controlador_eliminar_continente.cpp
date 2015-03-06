#include "controlador_eliminar_continente.h"
#include "vista_eliminar_continente.h"
#include "constructor_de_mapa.h"

void ControladorEliminarContinente::inicializar(){
	ContenedorContinentes* continentes = &(get_mapa().get_continentes());
	get_vista().set_continentes(continentes);
}

void ControladorEliminarContinente::manejar_evento_confirmar(){
	Continente* continente;
	/* Obtengo continentes segun su nombre... */
	foreach(IteradorNombresContinentes, i, this->contenedor_nombres_continentes){
		continente = this->get_mapa().get_continente(*i);
		this->get_constructor().eliminar_continente(continente);
	}
	this->get_contexto()->set_mapa_modificado(true);
	get_vista().cerrar();
}


void ControladorEliminarContinente::manejar_evento_cancelar(){
	get_vista().cerrar();
}


void ControladorEliminarContinente::manejar_evento_seleccionado(string nombre_continente){
	this->contenedor_nombres_continentes.push_back(nombre_continente);
}


void ControladorEliminarContinente::manejar_evento_desseleccionado(string nombre_continente){
	foreach(IteradorNombresContinentes, i, this->contenedor_nombres_continentes){
		if (*i == nombre_continente){
			this->contenedor_nombres_continentes.erase(i);
			break;
		}
	}
}