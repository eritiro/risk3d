#include "estrategia_edicion_adyacencia.h"
#include "controlador_editor_de_mapa.h"
#include "vista_editor_de_mapa.h"


EstrategiaEdicionAdyacencia::EstrategiaEdicionAdyacencia(){
	territorio_seleccionado = 0;
};


EstrategiaEdicionAdyacencia::~EstrategiaEdicionAdyacencia(){
}


void EstrategiaEdicionAdyacencia::efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada){
	territorio_seleccionado = 0;
	controlador->get_vista().refrescar_mapa(&controlador->get_mapa());
}


void EstrategiaEdicionAdyacencia::efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio){
	try{
		if(territorio_seleccionado == 0)
			territorio_seleccionado = territorio;
		else
		{
			if(territorio_seleccionado->es_adyacente_a(territorio))
				controlador->get_constructor().eliminar_adyacencia(territorio_seleccionado, territorio);
			else
				controlador->get_constructor().agregar_adyacencia(territorio_seleccionado, territorio);
		}
		controlador->get_vista().refrescar_mapa(&controlador->get_mapa(), territorio_seleccionado);
		controlador->get_contexto()->set_mapa_modificado(true);
	}
	catch(ExcepcionDeNegocio& ex){
		controlador->get_vista().mostrar_mensaje_alerta(ex.get_descripcion());
	}

}
