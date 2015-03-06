#include "controlador_crear_continente.h"
#include "vista_crear_continente.h"
#include "constructor_de_mapa.h"

void ControladorCrearContinente::inicializar(){
	// no hace nada.
}

void ControladorCrearContinente::manejar_evento_confirmar(){
	try{
		string nombre = this->get_vista().get_nombre_continente();
		int bonus = UtilidadesString::string_a_int(this->get_vista().get_bonus_continente());
		get_constructor().agregar_continente(nombre, bonus);
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


void ControladorCrearContinente::manejar_evento_cancelar(){
	get_vista().cerrar();
}

