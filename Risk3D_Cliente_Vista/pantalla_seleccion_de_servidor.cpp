#include "pantalla_seleccion_de_servidor.h"

using namespace std;

PantallaSeleccionDeServidor::PantallaSeleccionDeServidor(ContextoJuego* contexto) : VistaPantallaSeleccionDeServidor(contexto){
	
	this->get_controlador().inicializar();

	/* Creo ventana... */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Seleccione servidor...");
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);
	
	/* Creo etiquetas, botones y entradas de texto. */
	this->etiqueta_ingrese_servidor = gtk_label_new("Ingrese servidor:");
	this->etiqueta_ingrese_puerto = gtk_label_new("Ingrese puerto:");

	this->entrada_ingrese_servidor = gtk_entry_new();
	this->entrada_ingrese_puerto = gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(this->entrada_ingrese_puerto), 10);

	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");


	/* Organizo widgets. */
	this->vbox = gtk_vbox_new(FALSE, 0);
	this->hbox = gtk_hbox_new(FALSE, 0);
	this->hbox_ingrese_puerto = gtk_hbox_new(FALSE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->etiqueta_ingrese_servidor), FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->entrada_ingrese_servidor), FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(this->hbox_ingrese_puerto), GTK_WIDGET(this->etiqueta_ingrese_puerto), FALSE, FALSE, 25);
	gtk_box_pack_start(GTK_BOX(this->hbox_ingrese_puerto), GTK_WIDGET(this->entrada_ingrese_puerto), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->hbox_ingrese_puerto, FALSE, FALSE, 5);


	gtk_box_pack_start(GTK_BOX(this->hbox), GTK_WIDGET(this->boton_aceptar), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox), GTK_WIDGET(this->boton_cancelar), TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox), this->hbox, FALSE, FALSE, 10);

	gtk_container_set_border_width(GTK_CONTAINER(this->ventana), 5);
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox);

	
	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);


	/* Muestro ventana. */
	gtk_widget_show_all(this->ventana);

	gtk_dialog_run(GTK_DIALOG(this->ventana));

}


PantallaSeleccionDeServidor::~PantallaSeleccionDeServidor(){
}



string PantallaSeleccionDeServidor::get_nombre_servidor(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_ingrese_servidor)); 
}


string PantallaSeleccionDeServidor::get_puerto_servidor(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_ingrese_puerto)); 
}


void PantallaSeleccionDeServidor::mostrar_alerta(string mensaje){
	Error err(mensaje);
}


void PantallaSeleccionDeServidor::cerrar(){
	gtk_widget_destroy(this->ventana);
}


void PantallaSeleccionDeServidor::mostrar_seleccion_de_imperio(){
	PantallaSeleccionDeImperio pantalla_seleccion_de_imperio(this->get_contexto());
	this->cerrar();
}


/* Definicion de callbacks. */

void PantallaSeleccionDeServidor::on_destruir_ventana(GtkWidget* widget, gpointer data){
	PantallaSeleccionDeServidor* instancia = (PantallaSeleccionDeServidor*)data;
	gtk_widget_destroy(GTK_WIDGET(widget));
}

void PantallaSeleccionDeServidor::on_aceptar(GtkWidget* widget, gpointer data){
	PantallaSeleccionDeServidor* instancia = (PantallaSeleccionDeServidor*)data;
	instancia->get_controlador().manejar_evento_aceptar();
}


void PantallaSeleccionDeServidor::on_cancelar(GtkWidget* widget, gpointer data){
	PantallaSeleccionDeServidor* instancia = (PantallaSeleccionDeServidor*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}