#include "estrategia_eliminar_territorio.h"
#include "controlador_editor_de_mapa.h"
#include "vista_editor_de_mapa.h"

EstrategiaEliminarTerritorio::EstrategiaEliminarTerritorio(){
}

EstrategiaEliminarTerritorio::~EstrategiaEliminarTerritorio(){
}

void EstrategiaEliminarTerritorio::efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada){
}


void EstrategiaEliminarTerritorio::efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio){
	controlador->get_constructor().eliminar_territorio(territorio);
	controlador->get_vista().refrescar_mapa(&controlador->get_mapa());
	controlador->get_contexto()->set_mapa_modificado(true);
}
