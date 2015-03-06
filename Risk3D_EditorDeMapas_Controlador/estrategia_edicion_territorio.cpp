#include "estrategia_edicion_territorio.h"
#include "controlador_editor_de_mapa.h"
#include "vista_editor_de_mapa.h"


EstrategiaEdicionTerritorio::EstrategiaEdicionTerritorio(){};


EstrategiaEdicionTerritorio::~EstrategiaEdicionTerritorio(){}


void EstrategiaEdicionTerritorio::efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada){
	controlador->get_contexto()->set_es_territorio_nuevo(true);
	controlador->get_contexto()->set_coordenada_actual(coordenada);
	controlador->get_vista().abrir_ventana_edicion_territorio();
	controlador->get_vista().refrescar_mapa(&controlador->get_mapa());
}


void EstrategiaEdicionTerritorio::efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio){
	controlador->get_contexto()->set_es_territorio_nuevo(false);
	controlador->get_contexto()->set_territorio_actual(territorio);
	controlador->get_vista().abrir_ventana_edicion_territorio();
	controlador->get_vista().refrescar_mapa(&controlador->get_mapa());
}

