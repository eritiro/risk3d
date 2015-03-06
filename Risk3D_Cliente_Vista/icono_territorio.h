#ifndef ICONO_TERRITORIO_H_
#define ICONO_TERRITORIO_H_

#include <string>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "utilidades_string.h"
#include "tropa.h"
#include "controlador_pantalla_juego.h"

#define ALTO_ICONO 16
#define ANCHO_ICONO 16

using namespace std;

class IconoTerritorio {
	private:
		ControladorPantallaJuego* controlador;
		GtkTooltips* tooltip;
		GtkWidget* imagen;
		GtkWidget* icono_event_box;
		Tropa* tropa;
		string archivo_icono_sin_iluminacion;
		string archivo_icono_con_iluminacion;
		bool iluminado;
		static void on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);

	public:
		IconoTerritorio(Tropa* tropa, ControladorPantallaJuego* controlador, string archivo_icono, string archivo_icono_iluminado);
		Tropa* get_tropa();
		void set_iluminacion(bool valor);
		virtual ~IconoTerritorio();
		GtkWidget* get_widget();
};

#endif /* ICONO_TERRITORIO_H_ */
