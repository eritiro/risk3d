#ifndef ICONO_TERRITORIO_H_
#define ICONO_TERRITORIO_H_

#include <string>
#include <iostream>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "utilidades_string.h"
#include "territorio.h"
#include "controlador_editor_de_mapa.h"

#define ALTO_ICONO 16
#define ANCHO_ICONO 16

using namespace std;

const string ruta_icono_territorio_comun = "iconos/icono_naranja.jpg";
const string ruta_icono_territorio_activo = "iconos/icono_rojo.jpg";
const string ruta_icono_territorio_adyacente = "iconos/icono_amarillo.jpg";


class IconoTerritorio {
	protected:
		ControladorEditorDeMapa* controlador;
		GtkTooltips* tooltip;
		GtkWidget* imagen;
		GtkWidget* icono_event_box;
		Territorio* territorio;

		static void on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);

	public:
		IconoTerritorio(Territorio* territorio, ControladorEditorDeMapa* controlador);
		virtual ~IconoTerritorio();
		GtkWidget* get_widget();
};

#endif /* ICONO_TERRITORIO_H_ */
