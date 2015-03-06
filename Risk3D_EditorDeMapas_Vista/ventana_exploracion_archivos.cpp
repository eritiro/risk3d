#include "ventana_exploracion_archivos.h"



VentanaExploracionArchivos::VentanaExploracionArchivos(string titulo){
	this->file_selector = gtk_file_selection_new(titulo.c_str());
	gtk_window_set_position(GTK_WINDOW(this->file_selector), GTK_WIN_POS_CENTER);
	gtk_signal_connect(GTK_OBJECT(this->file_selector), "delete_event", GTK_SIGNAL_FUNC(on_destruir), this);
	g_signal_connect(GTK_FILE_SELECTION(this->file_selector)->ok_button, "clicked", G_CALLBACK(on_aceptar),this);
	g_signal_connect(GTK_FILE_SELECTION(this->file_selector)->cancel_button, "clicked", G_CALLBACK(on_cancelar), this);
}


string VentanaExploracionArchivos::elegir_archivo(){
	gtk_dialog_run(GTK_DIALOG(this->file_selector));
	return ruta;
}


VentanaExploracionArchivos::~VentanaExploracionArchivos(){}


/* Definicion de eventos. */

void VentanaExploracionArchivos::on_destruir(GtkWidget* widget, gpointer data){	
	VentanaExploracionArchivos* instancia = (VentanaExploracionArchivos*)data;
	gtk_widget_destroy(widget);
}


void VentanaExploracionArchivos::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaExploracionArchivos* instancia = (VentanaExploracionArchivos*)data;
	instancia->ruta = gtk_file_selection_get_filename(GTK_FILE_SELECTION(instancia->file_selector));
	gtk_widget_destroy(instancia->file_selector);
}


void VentanaExploracionArchivos::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaExploracionArchivos* instancia = (VentanaExploracionArchivos*)data;
	gtk_widget_destroy(instancia->file_selector);
	instancia->ruta = "";
}