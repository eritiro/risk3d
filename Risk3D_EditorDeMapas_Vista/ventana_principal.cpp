#include "ventana_principal.h"


VentanaPrincipal::VentanaPrincipal(ContextoEditor* contexto) : VistaEditorDeMapa(contexto){
}


void VentanaPrincipal::crear(){
	/* Creo la ventana principal. */
	this->ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Editor de Mapas.");
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_signal_connect(GTK_OBJECT(this->ventana), "destroy", GTK_SIGNAL_FUNC(on_destruir_ventana_principal), this);
	
	/* Creo barra de menu. */ 
	this->barra_menu = new MenuVentanaPrincipal(&get_controlador());


	/* Creao area de edicion. */
	this->area_de_edicion = new AreaDeEdicion(&this->get_controlador());
	

	/* Cero la barra de estado. */
	this->barra_de_estado = new BarraDeEstado();
	this->barra_de_estado->crear();
	

	/* Empaqueto y organizo widgets y recursos a mostrar. */
	this->vbox = gtk_vbox_new(FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->barra_menu->get_widget()), FALSE, TRUE, 0);
	
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->area_de_edicion->get_widget()), FALSE, TRUE, 0);
	
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->barra_de_estado->get_widget()), FALSE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(this->ventana), this->vbox);
	
	get_controlador().inicializar();


}

void VentanaPrincipal::mostrar_textura(string archivo){
	area_de_edicion->set_textura(archivo);
}

void VentanaPrincipal::mostrar_mensaje_barra_estado(string mensaje){
	/* Muestro mensaje en barra de estado. */
	id_contexto id = this->barra_de_estado->get_id_contexto("Contexto Ventana Principal");
	this->barra_de_estado->mostrar_mensaje(id, mensaje);
}


void VentanaPrincipal::mostrar_mensaje_alerta(string mensaje){
	Error err(mensaje);
}


void VentanaPrincipal::mostrar(){
	this->barra_menu->mostrar_barra_menu();
	this->barra_de_estado->mostrar();
	this->area_de_edicion->get_widget();
	gtk_widget_show(this->vbox);
	gtk_widget_show(this->ventana);
}


VentanaPrincipal::~VentanaPrincipal(){
	delete(this->barra_menu);
	delete(this->barra_de_estado);
	delete(this->area_de_edicion);
}


void VentanaPrincipal::destruir_ventana_principal(){
	gtk_main_quit();
}


string VentanaPrincipal::solicitar_archivo(string descripcion){
	VentanaExploracionArchivos ventana_exploracion_archivos(descripcion);
	return ventana_exploracion_archivos.elegir_archivo();
}


void VentanaPrincipal::abrir_ventana_crear_continente(){
	VentanaCrearContinente ventana_crear_continente(get_contexto());
}


void VentanaPrincipal::abrir_ventana_modificar_continente(){
	VentanaModificarContinente ventana_modificar_continente(get_contexto());
}


void VentanaPrincipal::abrir_ventana_eliminar_continente(){
	VentanaEliminarContinente ventana_eliminar_continente(get_contexto());
}


void VentanaPrincipal::ocultar_textura(){
	this->area_de_edicion->ocultar_textura();
}


void VentanaPrincipal::refrescar_mapa(Mapa* mapa){
	this->area_de_edicion->refrescar_mapa(mapa);
}

void VentanaPrincipal::refrescar_mapa(Mapa* mapa, Territorio* territorio_seleccionado){
	this->area_de_edicion->refrescar_mapa(mapa, territorio_seleccionado);
}

void VentanaPrincipal::abrir_ventana_edicion_territorio(){
	VentanaEdicionTerritorio ventana_edicion_territorio(get_contexto());
}

void VentanaPrincipal::abrir_ventana_administrar_objetivos(){
	VentanaAdministracionObjetivos ventana_administracion_objetivos(get_contexto());
}


void VentanaPrincipal::abrir_ventana_acerca_de(){
	VentanaAcercaDe ventana_acerca_de;
}


bool VentanaPrincipal::elegir_respuesta(string descripcion){
	VentanaPreguntaSiNo ventana_pregunta(descripcion);
	return ventana_pregunta.elegir_respuesta();
}


/* Definicion de callbacks. */

void VentanaPrincipal::on_destruir_ventana_principal(GtkWidget* widget, gpointer data){
	VentanaPrincipal* instancia = (VentanaPrincipal*)data;
	instancia->get_controlador().manejar_evento_destruir_ventana_principal();
}

