#include "pantalla_creacion_de_juego.h"


PantallaCreacionDeJuego::PantallaCreacionDeJuego(ContextoJuego* contexto) : VistaPantallaCreacionDeJuego(contexto){
	/* Creo ventana... */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	//gtk_window_resize(GTK_WINDOW(this->ventana), 250, 100);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Crear juego...");
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	
	/* Creo etiquetas, entradas de texto y botones. */
	this->etiqueta_seleccione_mapa = gtk_label_new("Ingrese ruta del mapa a utilizar:");
	this->etiqueta_ingrese_puerto = gtk_label_new("Ingrese numero de puerto a utilizar: ");

	this->entrada_seleccione_mapa = gtk_entry_new();
	this->entrada_ingrese_puerto = gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(this->entrada_ingrese_puerto), 5);

	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	this->boton_examinar = gtk_button_new_with_label("Examinar");

	/* Organizo widgets. */
	this->vbox = gtk_vbox_new(FALSE, 0);
	this->hbox_entrada_mapa = gtk_hbox_new(FALSE, 0);
	this->hbox_entrada_puerto = gtk_hbox_new(FALSE, 0);
	this->hbox_botones = gtk_hbox_new(FALSE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->etiqueta_seleccione_mapa), FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(this->hbox_entrada_mapa), GTK_WIDGET(this->entrada_seleccione_mapa), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_entrada_mapa), GTK_WIDGET(this->boton_examinar), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->hbox_entrada_mapa), FALSE, FALSE, 0);

	
	gtk_box_pack_start(GTK_BOX(this->hbox_entrada_puerto), GTK_WIDGET(this->etiqueta_ingrese_puerto), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_entrada_puerto), GTK_WIDGET(this->entrada_ingrese_puerto), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->hbox_entrada_puerto), FALSE, FALSE, 10);
	
	gtk_box_pack_start(GTK_BOX(this->hbox_botones), GTK_WIDGET(this->boton_aceptar), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_botones), GTK_WIDGET(this->boton_cancelar), TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->hbox_botones), FALSE, FALSE, 0);

	
	gtk_container_set_border_width(GTK_CONTAINER(this->ventana), 5);
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox);


	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_examinar), "clicked", GTK_SIGNAL_FUNC(on_examinar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);

	/* Muestro widgets. */
	gtk_widget_show_all(this->ventana);

	/* Main de ventana */
	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


void PantallaCreacionDeJuego::mostrar_alerta(string mensaje){
	Error err(mensaje);
}


void PantallaCreacionDeJuego::cerrar(){
	gtk_widget_destroy(GTK_WIDGET(this->ventana));
}


string PantallaCreacionDeJuego::solicitar_archivo(string descripcion){
	VentanaExploracionArchivos ventana_exploracion_archivos(descripcion);
	return ventana_exploracion_archivos.elegir_archivo();
}


string PantallaCreacionDeJuego::get_ruta_mapa_seleccionado(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_seleccione_mapa));
}


void PantallaCreacionDeJuego::set_ruta_mapa_seleccionado(string valor){
	gtk_entry_set_text(GTK_ENTRY(this->entrada_seleccione_mapa), valor.c_str());
}


string PantallaCreacionDeJuego::get_puerto(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_ingrese_puerto));
}


void PantallaCreacionDeJuego::mostrar_seleccion_de_imperio(){
	PantallaSeleccionDeImperio pantalla_seleccion_de_imperio(this->get_contexto());
	this->cerrar();
}


/* Definicion de callbacks */

void PantallaCreacionDeJuego::on_destruir_ventana(GtkWidget* widget, gpointer data){
	PantallaCreacionDeJuego* instancia = (PantallaCreacionDeJuego*)data;
	gtk_widget_destroy(GTK_WIDGET(widget));
}


void PantallaCreacionDeJuego::on_examinar(GtkWidget* widget, gpointer data){
	PantallaCreacionDeJuego* instancia = (PantallaCreacionDeJuego*)data;
	instancia->get_controlador().manejar_evento_examinar();
}

void PantallaCreacionDeJuego::on_cancelar(GtkWidget* widget, gpointer data){
	PantallaCreacionDeJuego* instancia = (PantallaCreacionDeJuego*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}


void PantallaCreacionDeJuego::on_aceptar(GtkWidget* widget, gpointer data){
	PantallaCreacionDeJuego* instancia = (PantallaCreacionDeJuego*)data;
	instancia->get_controlador().manejar_evento_aceptar();
}