#include "controlador_administrar_objetivos.h"
#include "vista_administrar_objetivos.h"


void ControladorAdministrarObjetivos::inicializar(){
	this->get_contexto()->set_requisito_seleccionado(0);
	this->get_contexto()->set_es_nuevo_requisito(false);
	Mapa* mapa = &(this->get_mapa());
	ContenedorRequisitos contenedor_requisitos = mapa->get_configuracion().get_requisitos_de_ocupacion();
	get_vista().set_requisitos(contenedor_requisitos);
}


void ControladorAdministrarObjetivos::manejar_evento_cancelar(){
	get_vista().cerrar();
}


void ControladorAdministrarObjetivos::manejar_evento_agregar_nuevo(){
	this->get_contexto()->set_es_nuevo_requisito(true);
	ContenedorContinentes* contenedor_continentes = &(get_mapa().get_continentes());
	if (contenedor_continentes->size())
		get_vista().abrir_ventana_edicion_objetivo();
	else
		get_vista().mostrar_mensaje_alerta("Debe crear al menos un continente.");
}


void ControladorAdministrarObjetivos::manejar_evento_modificar(RequisitoDeOcupacion* requisito){
	this->get_contexto()->set_es_nuevo_requisito(false);
	this->get_contexto()->set_requisito_seleccionado(requisito);
	get_vista().abrir_ventana_edicion_objetivo();
}


void ControladorAdministrarObjetivos::manejar_evento_actualizar(){
	Mapa* mapa = &(this->get_mapa());
	ContenedorRequisitos contenedor_requisitos = mapa->get_configuracion().get_requisitos_de_ocupacion();
	this->get_vista().actualizar(contenedor_requisitos);
}


void ControladorAdministrarObjetivos::manejar_evento_eliminar(RequisitoDeOcupacion* requisito){
	get_constructor().eliminar_requisito(requisito);
	Mapa* mapa = &(this->get_mapa());
	ContenedorRequisitos contenedor_requisitos = mapa->get_configuracion().get_requisitos_de_ocupacion();
	this->get_vista().actualizar(contenedor_requisitos);
	get_contexto()->set_mapa_modificado(true);
}