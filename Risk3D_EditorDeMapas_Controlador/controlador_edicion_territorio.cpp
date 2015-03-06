#include "controlador_edicion_territorio.h"
#include "vista_edicion_territorio.h"
#include "constructor_de_mapa.h"

void ControladorEdicionTerritorio::inicializar(){
	ContenedorContinentes* continentes = &(get_mapa().get_continentes());

	if (get_contexto()->hay_mapa_activo()){
		Coordenada coordenada = get_contexto()->get_coordenada_actual();
		ContenedorContinentes* continentes = &(get_mapa().get_continentes());
		/*  Si se agrega nuevo territorio... */
		if (this->get_contexto()->get_es_territorio_nuevo()){
			get_vista().set_continentes(continentes);
			get_vista().set_coordenadas(coordenada.get_x(), coordenada.get_y());
		}
		else /* Si se va a editar territorio existente... */
		{
			get_vista().set_continentes(continentes, this->get_contexto()->get_territorio_actual()->get_continente());
			get_vista().set_nombre_territorio(this->get_contexto()->get_territorio_actual()->get_nombre());
			get_vista().set_coordenadas(this->get_contexto()->get_territorio_actual()->get_posicion().get_x(),
						this->get_contexto()->get_territorio_actual()->get_posicion().get_y());
		}
	}
}


void ControladorEdicionTerritorio::manejar_evento_confirmar(){
	/* Si el territorio es nuevo... */
	try {
		if (this->get_contexto()->get_es_territorio_nuevo()){
			Coordenada coordenada(get_vista().get_coordenada_x(), get_vista().get_coordenada_y());
			string nombre_continente = get_vista().get_nombnre_continente();
			string nombre_territorio = get_vista().get_nombre_territorio();
			Continente* continente = this->get_mapa().get_continente(nombre_continente);
			this->get_constructor().agregar_territorio(nombre_territorio, coordenada, continente);
			this->get_contexto()->set_mapa_modificado(true);
		}
		else /* Si es territorio existente... */
		{
			string nombre_continente = get_vista().get_nombnre_continente();
			string nombre_territorio = get_vista().get_nombre_territorio();
			Continente* continente = this->get_mapa().get_continente(nombre_continente);
			this->get_constructor().modificar_territorio(this->get_contexto()->get_territorio_actual(), nombre_territorio, continente);
			this->get_contexto()->set_mapa_modificado(true);
		}
		get_vista().cerrar();
	}
	catch(ExcepcionDeNegocio& ex){
		get_vista().mostrar_alerta(ex.get_descripcion());
	}
}


void ControladorEdicionTerritorio::manejar_evento_cancelar(){
	get_vista().cerrar();
}