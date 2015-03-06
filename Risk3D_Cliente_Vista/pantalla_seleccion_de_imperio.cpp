#include "pantalla_seleccion_de_imperio.h"

using namespace std;

PantallaSeleccionDeImperio::PantallaSeleccionDeImperio(ContextoJuego* contexto) : VistaPantallaSeleccionDeImperio(contexto){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Seleccione imperio...");
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE); 
	

	/* Creo entradas de texto, etiquetas, menu desplegable, lista items y botones... */
	this->entrada_ingrese_nombre = gtk_entry_new();
	this->etiqueta_ingrese_nombre = gtk_label_new("Ingrese su nombre:");
	this->etiqueta_seleccione_color = gtk_label_new("Seleccione un color:");

	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	
	this->lista_items_menu_desplegable = NULL;
	
	this->menu_desplegable = gtk_combo_new();
	gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry), FALSE);

	/* Calbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);

	string rojo = VistaColorImperio::get_rojo().get_string_color();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, (void*)rojo.c_str());

	string verde = VistaColorImperio::get_verde().get_string_color();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, (void*)verde.c_str());

	string azul = VistaColorImperio::get_azul().get_string_color();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, (void*)azul.c_str());

	string naranja = VistaColorImperio::get_naranja().get_string_color();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, (void*)naranja.c_str());
	
	string rosa = VistaColorImperio::get_rosa().get_string_color();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, (void*)rosa.c_str());
	
	string turquesa = VistaColorImperio::get_turquesa().get_string_color();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, (void*)turquesa.c_str());

	gtk_combo_set_popdown_strings (GTK_COMBO(this->menu_desplegable), this->lista_items_menu_desplegable);

	
	/* Creo vertical box y organizo widgets. */
	this->vbox = gtk_vbox_new(FALSE, 5);
	this->hbox = gtk_hbox_new(FALSE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_seleccione_color, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->menu_desplegable, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_ingrese_nombre, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->entrada_ingrese_nombre, FALSE, FALSE, 0);
	
	gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_aceptar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_cancelar, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox), this->hbox, FALSE, FALSE, 15);
	
	
	gtk_container_set_border_width(GTK_CONTAINER(this->ventana), 5);
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox);

	
	gtk_widget_show_all(this->ventana);

	this->get_controlador().inicializar();
	
	/* Inicializo timeout. */
	this->id_temporizador = gtk_timeout_add(MILISEGUNDOS_POOLEO_CONTROLADOR, on_temporizador, this);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


PantallaSeleccionDeImperio::~PantallaSeleccionDeImperio(){
	gtk_timeout_remove(this->id_temporizador);
}


void PantallaSeleccionDeImperio::mostrar_pantalla_previa_al_juego(){
	PantallaPrevia pantalla_previa(this->get_contexto());
	this->cerrar();
}



void PantallaSeleccionDeImperio::mostrar_alerta(string mensaje){
	Error err(mensaje);
}


string PantallaSeleccionDeImperio::get_nombre_emperador(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_ingrese_nombre));
}


ColorImperio PantallaSeleccionDeImperio::get_color_imperio(){
	GTK_COMBO(this->menu_desplegable);
	VistaColorImperio vista(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry)));
	return vista.get_color_imperio();
}


void PantallaSeleccionDeImperio::cerrar(){
	gtk_timeout_remove(this->id_temporizador);
	gtk_widget_destroy(this->ventana);
}




/* Definicion de callbacks. */

void PantallaSeleccionDeImperio::on_aceptar(GtkWidget* widget, gpointer data){
	PantallaSeleccionDeImperio* instancia = (PantallaSeleccionDeImperio*)data;
	instancia->get_controlador().manejar_evento_aceptar();
}


void PantallaSeleccionDeImperio::on_cancelar(GtkWidget* widget, gpointer data){
	PantallaSeleccionDeImperio* instancia = (PantallaSeleccionDeImperio*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}


gboolean PantallaSeleccionDeImperio::on_destruir_ventana(GtkWidget* widget, gpointer data){
	gtk_widget_destroy(widget);
	return FALSE;
}


gint PantallaSeleccionDeImperio::on_temporizador(gpointer data){
	PantallaSeleccionDeImperio* instancia = (PantallaSeleccionDeImperio*)data;
	instancia->get_controlador().manejar_evento_temporizador();
	return TRUE;
}