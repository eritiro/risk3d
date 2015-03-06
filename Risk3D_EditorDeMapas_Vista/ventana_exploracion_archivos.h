#ifndef VENTANA_EXPLORACION_ARCHIVOS_H_
#define VENTANA_EXPLORACION_ARCHIVOS_H_

#include <gtk/gtk.h>
#include <string>
#include "error.h"


using namespace std;

class VentanaExploracionArchivos {
	private:
		string ruta;
		GtkWidget* file_selector;
		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static void on_destruir(GtkWidget* widget, gpointer data);


	public:
		VentanaExploracionArchivos(string titulo);
		~VentanaExploracionArchivos();
		string elegir_archivo();
};


#endif /* VENTANA_EXPLORACION_ARCHIVOS_H_ */