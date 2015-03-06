#include "ventana_de_informacion.h"


VentanaDeInformacion::VentanaDeInformacion(){
	this->frame_info = gtk_frame_new("Informacion");
	gtk_widget_set_size_request (this->frame_info, 200, 60);

	
	this->vbox = gtk_vbox_new(FALSE, 0);
	this->etiqueta_nombre_emperador = gtk_label_new("Emperador: ");
	this->etiqueta_cantidad_territorios = gtk_label_new("Total territorios: ");
	this->etiqueta_ejercitos_disponibles = gtk_label_new("Ejercitos disponibles: ");

	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_nombre_emperador, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_cantidad_territorios, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_ejercitos_disponibles, FALSE, FALSE, 0);


	gtk_container_add(GTK_CONTAINER(this->frame_info), this->vbox);
}


VentanaDeInformacion::~VentanaDeInformacion(){
}


void VentanaDeInformacion::actualizar(Imperio* imperio){

	string str_nombre_emperador = "Emperador: " + imperio->get_nombre_emperador();
	string str_ejercitos_disponibles = "Ejercitos disponibles: " + UtilidadesString::int_a_string(imperio->get_ejercitos_disponibles());
	string str_cantidad_territorios = "Total territorios: " + UtilidadesString::int_a_string(imperio->get_tropas().size());
	gtk_label_set_text(GTK_LABEL(this->etiqueta_nombre_emperador), str_nombre_emperador.c_str());
	gtk_label_set_text(GTK_LABEL(this->etiqueta_cantidad_territorios), str_cantidad_territorios.c_str());
	gtk_label_set_text(GTK_LABEL(this->etiqueta_ejercitos_disponibles), str_ejercitos_disponibles.c_str());
}


GtkWidget* VentanaDeInformacion::get_widget(){
	return this->frame_info;
}
