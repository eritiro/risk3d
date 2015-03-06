#include "ventana_mostrar_objetivo.h"


VentanaMostrarObjetivo::VentanaMostrarObjetivo(string objetivo){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Objetivos...");
	gtk_window_resize(GTK_WINDOW(this->ventana), 280, 100);
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_modal(GTK_WINDOW(this->ventana), TRUE);

	/* Creo otros widgets... */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);

	this->etiqueta_objetivo = gtk_label_new(objetivo.c_str());
	this->hbox = gtk_hbox_new(FALSE, 0);
	this->vbox = gtk_vbox_new(FALSE, 0);
	this->frame = gtk_frame_new("Objetivos...");
	gtk_widget_set_size_request(this->frame, 280, 100);
	
	gtk_container_add(GTK_CONTAINER(this->frame), this->etiqueta_objetivo);

	gtk_box_pack_start(GTK_BOX(this->vbox), this->frame, FALSE, FALSE, 0);

	gtk_container_set_border_width(GTK_CONTAINER(this->ventana), 10);
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox);


	gtk_widget_show_all(this->ventana);

	gtk_dialog_run(GTK_DIALOG(this->ventana));

	
}


VentanaMostrarObjetivo::~VentanaMostrarObjetivo(){
}


/* Definicion de callbacks. */

void VentanaMostrarObjetivo::on_cerrar(GtkWidget* widget, gpointer data){
	VentanaMostrarObjetivo* instancia = (VentanaMostrarObjetivo*)data;
	gtk_widget_destroy(instancia->ventana);
}

void VentanaMostrarObjetivo::on_destruir_ventana(GtkWidget* widget, gpointer data){
	gtk_widget_destroy(widget);
}