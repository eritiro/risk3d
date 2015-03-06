#ifndef VENTANA_DE_INFORMACION_H_
#define VENTANA_DE_INFORMACION_H_

#include <gtk/gtk.h>
#include <string>
#include "utilidades_string.h"
#include "imperio.h"

using std::string;

class VentanaDeInformacion {
	private:
		GtkWidget* frame_info;
		GtkWidget* etiqueta_nombre_emperador;
		GtkWidget* etiqueta_ejercitos_disponibles;
		GtkWidget* etiqueta_cantidad_territorios;
		GtkWidget* vbox;

	public:
		VentanaDeInformacion();
		~VentanaDeInformacion();
		void actualizar(Imperio* imperio);
		GtkWidget* get_widget();
};


#endif /* VENTANA_DE_INFORMACION_H_ */