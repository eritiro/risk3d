#include "barra_de_estado.h"

BarraDeEstado::BarraDeEstado(){}


void BarraDeEstado::crear(){
	this->barra_de_estado = gtk_statusbar_new();
}


void BarraDeEstado::mostrar(){
	gtk_widget_show(this->barra_de_estado);
}


id_contexto BarraDeEstado::get_id_contexto(string descripcion){
	return gtk_statusbar_get_context_id(GTK_STATUSBAR(this->barra_de_estado), descripcion.c_str());
}


id_mensaje BarraDeEstado::mostrar_mensaje(id_contexto id, string mensaje){
	return gtk_statusbar_push(GTK_STATUSBAR(this->barra_de_estado), id, mensaje.c_str());
}


void BarraDeEstado::quitar_mensaje(id_contexto id){
	gtk_statusbar_pop(GTK_STATUSBAR(this->barra_de_estado), id);
}


void BarraDeEstado::eliminar_mensaje(id_contexto id_con, id_mensaje id_msg){
	gtk_statusbar_remove(GTK_STATUSBAR(this->barra_de_estado), id_con, id_msg);
}


GtkWidget* BarraDeEstado::get_widget(){
	return this->barra_de_estado;
}


BarraDeEstado::~BarraDeEstado(){}
