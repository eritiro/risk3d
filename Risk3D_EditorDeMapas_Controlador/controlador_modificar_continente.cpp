#include "controlador_modificar_continente.h"
#include "vista_modificar_continente.h"

void ControladorModificarContinente::inicializar()
{
	ContenedorContinentes* continentes = &(get_mapa().get_continentes());
	get_vista().set_continentes(continentes);
}


void ControladorModificarContinente::manejar_evento_cargar_informacion_continente(){
	ContenedorContinentes* continentes = &(get_mapa().get_continentes());
	string nombre_continente_seleccionado = get_vista().get_nombre_continente_seleccionado();
	get_vista().set_continente_seleccionado(continentes, nombre_continente_seleccionado);
}


void ControladorModificarContinente::manejar_evento_cancelar(){
	get_vista().cerrar();
}


void ControladorModificarContinente::manejar_evento_confirmar(){
	try{
		string nombre = this->get_vista().get_nombre_continente_seleccionado();
		string nuevo_nombre = this->get_vista().get_nuevo_nombre_continente();
		int nuevo_bonus = UtilidadesString::string_a_int(this->get_vista().get_nuevo_bonus_continente());
		Continente* continente = get_mapa().get_continente(nombre);
		get_constructor().modificar_continente(continente, nuevo_nombre, nuevo_bonus);
		this->get_contexto()->set_mapa_modificado(true);
		get_vista().cerrar();
	}
	catch(ExcepcionDeParseo){
		get_vista().mostrar_alerta("Los valores no son validos.");
	}
	catch(ExcepcionDeNegocio& ex){
		get_vista().mostrar_alerta(ex.get_descripcion());
	}
}
