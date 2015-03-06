#include "ventana_pregunta.h"


VentanaPregunta::VentanaPregunta(string pregunta){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Pregunta!");
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);


	/* Creo widgets. */
	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	this->entrada_respuesta = gtk_entry_new();
	this->etiqueta_pregunta = gtk_label_new(pregunta.c_str());
	this->vbox = gtk_vbox_new(FALSE, 0);
	this->hbox = gtk_hbox_new(FALSE, 0);

	/* Organizo widgets. */
	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_pregunta, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->entrada_respuesta, FALSE, FALSE, 3);

	gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_aceptar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_cancelar, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox), this->hbox, FALSE, FALSE, 5);

	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox);

	

	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);


	/* Muestro widgets. */
	gtk_window_set_modal(GTK_WINDOW(this->ventana), TRUE);
	gtk_widget_show_all(this->ventana);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaPregunta::~VentanaPregunta(){
}


string VentanaPregunta::get_respuesta(){
	return this->respuesta;
}


/* Definicion de callbacks. */

void VentanaPregunta::on_destruir_ventana(GtkWidget* widget, gpointer data){
	VentanaPregunta* instancia = (VentanaPregunta*)data;
	gtk_widget_destroy(widget);
}


void VentanaPregunta::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaPregunta* instancia = (VentanaPregunta*)data;
	instancia->respuesta = gtk_entry_get_text(GTK_ENTRY(instancia->entrada_respuesta));
	gtk_widget_destroy(instancia->ventana);
}


void VentanaPregunta::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaPregunta* instancia = (VentanaPregunta*)data;
	instancia->respuesta = "";
	gtk_widget_destroy(instancia->ventana);
}

