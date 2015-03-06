#ifndef PANTALLA_SELECCION_DE_IMPERIO_H_
#define PANTALLA_SELECCION_DE_IMPERIO_H_

#include <gtk/gtk.h>
#include <glib.h>

#include <iostream>
#include "vista_pantalla_seleccion_de_imperio.h"
#include "pantalla_previa.h"
#include "error.h"
#include "vista_color_imperio.h"
#include "constantes_vista.h"

class PantallaSeleccionDeImperio : public VistaPantallaSeleccionDeImperio {
	private:		
		GtkWidget* ventana;
		GtkWidget* etiqueta_seleccione_color;
		GtkWidget* menu_desplegable;
		GtkWidget* etiqueta_ingrese_nombre;
		GtkWidget* entrada_ingrese_nombre;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* vbox;
		GtkWidget* hbox;
		GList* lista_items_menu_desplegable;
		int id_temporizador;

		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static gboolean on_destruir_ventana(GtkWidget* widget, gpointer data);
		static gint on_temporizador(gpointer data);

	public:			
		PantallaSeleccionDeImperio(ContextoJuego* contexto);
		~PantallaSeleccionDeImperio();
		string get_nombre_emperador();
		ColorImperio get_color_imperio();
		void mostrar_pantalla_previa_al_juego();
		void mostrar_alerta(string mensaje);
		void cerrar();
};

#endif /* PANTALLA_SELECCION_DE_IMPERIO_H_ */
