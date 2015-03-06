#ifndef TEXTURA_H_
#define TEXTURA_H_

#include <gtk/gtk.h>
#include <string>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "error.h"

using namespace std;

class Textura {
	private:
		string ruta;
		GtkWidget* imagen;
		GdkPixbuf* pixbuf;
		int ancho;
		int alto;
		
	public:
		Textura();
		~Textura();
		void set_ruta(string ruta);
		string get_ruta();
		bool cargar();
		GtkWidget* get_ptr_widget_imagen();
		int get_ancho();
		int get_alto();
};


#endif /* TEXTURA_H_ */