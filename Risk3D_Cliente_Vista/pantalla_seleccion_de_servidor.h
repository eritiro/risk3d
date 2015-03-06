#ifndef PANTALLA_SELECCION_DE_SERVIDOR_H_
#define PANTALLA_SELECCION_DE_SERVIDOR_H_

#include <iostream>
#include <gtk/gtk.h>
#include <glib.h>
#include "vista_pantalla_seleccion_de_servidor.h"
#include "pantalla_seleccion_de_imperio.h"
#include "error.h"


class PantallaSeleccionDeServidor : public VistaPantallaSeleccionDeServidor {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_ingrese_servidor;
		GtkWidget* etiqueta_ingrese_puerto;
		GtkWidget* entrada_ingrese_servidor;
		GtkWidget* entrada_ingrese_puerto;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* vbox;
		GtkWidget* hbox;
		GtkWidget* hbox_ingrese_puerto;

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);

	public:			
		PantallaSeleccionDeServidor(ContextoJuego* contexto);
		~PantallaSeleccionDeServidor();
		void mostrar_seleccion_de_imperio();
		void mostrar_alerta(string mensaje);
		void cerrar();
		string get_nombre_servidor();
		string get_puerto_servidor();
};

#endif /* PANTALLA_SELECCION_DE_SERVIDOR_H_ */
