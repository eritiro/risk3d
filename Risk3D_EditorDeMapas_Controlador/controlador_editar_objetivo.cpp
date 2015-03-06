#include "controlador_editar_objetivo.h"
#include "vista_editar_objetivo.h"

//aux
#include <iostream>
#include "utilidades_string.h"
using std::cout;
using std::endl;
//


void ControladorEditarObjetivo::inicializar(){
	this->contenedor_continentes = &(get_mapa().get_continentes());
	if (this->get_contexto()->get_es_nuevo_requisito())
		get_vista().set_continentes_default(contenedor_continentes);
	else
	{
		foreach(IteradorContinentes, i, *contenedor_continentes){
			get_vista().agregar_continente_valor((*i), this->get_contexto()->get_requisito_seleccionado()->get_territorios_a_conquistar_por_continente(*i));
	
		}
	}
}


void ControladorEditarObjetivo::manejar_evento_cancelar(){
	get_vista().cerrar();
}


void ControladorEditarObjetivo::manejar_evento_aceptar(){
	
	RequisitoDeOcupacion* requisito;

	if (this->get_contexto()->get_es_nuevo_requisito())
		requisito = get_constructor().agregar_requisito();
	else
		requisito = this->get_contexto()->get_requisito_seleccionado();
	
	foreach(IteradorContinentes, i, *(this->contenedor_continentes)){
		requisito->set_requerimiento(*i, get_vista().get_valor_por_continente(*i));
	}
	
	get_contexto()->set_mapa_modificado(true);
	get_vista().cerrar();
}
