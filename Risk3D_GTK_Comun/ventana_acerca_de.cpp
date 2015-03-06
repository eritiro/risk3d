#include "ventana_acerca_de.h"


VentanaAcercaDe::VentanaAcercaDe(){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Acerca de...");
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_resize(GTK_WINDOW(this->ventana), 250, 150);
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);

	/* Creo frame. */
	this->frame = gtk_frame_new("Risk 3D...");
	gtk_widget_set_size_request (this->frame, 250, 150);

	/* creo string y label... */
	string autores = "Autores:\n";
	autores += "Emiliano Ritiro.\n";
	autores += "Mariano Quiroga De Candia.\n";
	autores += "Laura Gonzales.\n";
	autores += "\n";
	string agradecimientos = "Agradecemos a Nicolas Longhitano, por toda\n" ;
	agradecimientos += "su colaboracion, asi como tambien a todos\n";
	agradecimientos += "aquellos que hicieron posible nuestra plena\n";
	agradecimientos += "dedicacion en el proyecto. Nuestros saludos!";

	string acerca_de = autores + agradecimientos;
	this->etiqueta_texto = gtk_label_new(acerca_de.c_str());

	gtk_container_set_border_width(GTK_CONTAINER(this->ventana), 8);
	gtk_container_add(GTK_CONTAINER(this->frame), this->etiqueta_texto);
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->frame);

	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);

	gtk_window_set_modal(GTK_WINDOW(this->ventana), TRUE);

	gtk_widget_show_all(GTK_WIDGET(this->ventana));

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaAcercaDe::~VentanaAcercaDe(){
}


/* Definicion de callbacks. */

void VentanaAcercaDe::on_destruir_ventana(GtkWidget* widget, gpointer data){
	VentanaAcercaDe* instancia = (VentanaAcercaDe*)data;	
	gtk_widget_destroy(widget);
}