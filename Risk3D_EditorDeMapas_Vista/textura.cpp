#include "textura.h"


Textura::Textura(){}


void Textura::set_ruta(string ruta){
	this->ruta = ruta;
}


string Textura::get_ruta(){
	return this->ruta;
}


GtkWidget* Textura::get_ptr_widget_imagen(){
	return this->imagen;
}


bool Textura::cargar(){
	if (!this->ruta.empty()){
		this->pixbuf = gdk_pixbuf_new_from_file(this->ruta.c_str(), NULL);
		if (this->pixbuf){
			this->imagen = gtk_image_new_from_pixbuf(this->pixbuf);
			if (this->imagen){
				this->ancho = gdk_pixbuf_get_width(this->pixbuf);
				this->alto = gdk_pixbuf_get_height(this->pixbuf);
				return true;
			}
		}
	}
	return false;
}


Textura::~Textura(){}


int Textura::get_alto(){
	return this->alto;
}


int Textura::get_ancho(){
	return this->ancho;
}
