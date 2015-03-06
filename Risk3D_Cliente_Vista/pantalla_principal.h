#ifndef PANTALLA_PRINCIPAL_H_
#define PANTALLA_PRINCIPAL_H_

#include <iostream>
#include <gtk/gtk.h>
#include "vista_pantalla_principal.h"


class PantallaPrincipal : public VistaPantallaPrincipal {
	private:
		GtkWidget* ventana_principal;
		GtkWidget* boton_crear_juego;
		GtkWidget* boton_unirse_a_juego;
		GtkWidget* boton_salir;
		GtkWidget* vbox;

		static void on_destruir_ventana_principal(GtkWidget* widget, gpointer data);
		static void on_crear_juego(GtkWidget* widget, gpointer data);
		static void on_unirse_a_juego(GtkWidget* widget, gpointer data);
		static void on_salir(GtkWidget* widget, gpointer data);

		void abrir_ventana_crear_juego();
		void abrir_ventana_seleccion_servidor();


	public:			
		PantallaPrincipal(ContextoJuego* contexto);
		void cerrar();
};

#endif /* PANTALLA_PRINCIPAL_H_ */




