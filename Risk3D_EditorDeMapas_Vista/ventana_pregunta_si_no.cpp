#include "ventana_pregunta_si_no.h"


VentanaPreguntaSiNo::VentanaPreguntaSiNo(string pregunta){
	this->ventana = gtk_dialog_new();
	gtk_window_resize(GTK_WINDOW(this->ventana), 300, 100);
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Pregunta!");
	this->pregunta = gtk_label_new (pregunta.c_str());
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->pregunta, TRUE, TRUE, 0);
	gtk_dialog_set_has_separator (GTK_DIALOG(this->ventana), FALSE);

	this->boton = gtk_button_new_with_label("Si");
	GTK_WIDGET_SET_FLAGS(this->boton, GTK_CAN_DEFAULT);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->action_area), this->boton, TRUE, TRUE, 0);
	gtk_widget_show(this->boton);
	gtk_signal_connect(GTK_OBJECT(this->boton), "clicked", GTK_SIGNAL_FUNC(on_si), this);

	this->boton = gtk_button_new_with_label("No");
	GTK_WIDGET_SET_FLAGS(this->boton, GTK_CAN_DEFAULT);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->action_area), this->boton, TRUE, TRUE, 0);
	gtk_widget_grab_default(this->boton);
	gtk_widget_show(this->boton);
	gtk_signal_connect(GTK_OBJECT(this->boton), "clicked", GTK_SIGNAL_FUNC(on_no), this);

	gtk_widget_show(this->pregunta);
	gtk_widget_show(this->ventana);
	gtk_grab_add(this->ventana);

}


VentanaPreguntaSiNo::~VentanaPreguntaSiNo(){
}


bool VentanaPreguntaSiNo::elegir_respuesta(){
	gtk_dialog_run(GTK_DIALOG(this->ventana));
	return respuesta;
}


/* Definicion de callbacks. */

void VentanaPreguntaSiNo::on_si(GtkWidget* widget, gpointer data){
	VentanaPreguntaSiNo* instancia = (VentanaPreguntaSiNo*)data;
	instancia->respuesta = true;
	gtk_widget_destroy(instancia->ventana);
}


void VentanaPreguntaSiNo::on_no(GtkWidget* widget, gpointer data){
	VentanaPreguntaSiNo* instancia = (VentanaPreguntaSiNo*)data;
	instancia->respuesta = false;
	gtk_widget_destroy(instancia->ventana);
}
