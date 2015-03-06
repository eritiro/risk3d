#ifndef PANTALLA_PREVIA_H_
#define PANTALLA_PREVIA_H_

#define GTK_ENABLE_BROKEN

#include <gtk/gtk.h>
#include <iostream>
#include "vista_pantalla_previa.h"
#include "pantalla_juego.h"
#include "error.h"
#include "vista_color_imperio.h"
#include "constantes_vista.h"

class PantallaPrevia : public VistaPantallaPrevia {
	private:
		GtkWidget* ventana;
		GtkWidget* ventana_chat;
		GtkWidget* entrada_chat;
		GtkWidget* etiqueta_chat;
		GtkWidget* boton_enviar;
		GtkWidget* boton_comenzar;
		GtkWidget* barra_desplazamiento_vertical;
		GtkWidget* hbox_ventana_chat;
		GtkWidget* vbox;
		GtkWidget* hbox;
		int id_temporizador;
		

		static gboolean on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_enviar(GtkWidget* widget, gpointer data);
		static gint on_temporizador(gpointer data);
		static void on_comenzar(GtkWidget* widget, gpointer data);

	public:			
		PantallaPrevia(ContextoJuego* contexto);
		~PantallaPrevia();

		void mostrar();
		
		void mostrar_mensaje(string mensaje);
		void mostrar_alerta(string mensaje);
		void mostrar_chat(Imperio* imperio, string mensaje);

		void mostrar_juego();
		void cerrar();
};

#endif /* PANTALLA_PREVIA_H_ */
