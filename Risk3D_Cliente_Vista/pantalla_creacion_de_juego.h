#ifndef PANTALLA_CREACION_DE_JUEGO_H_
#define PANTALLA_CREACION_DE_JUEGO_H_

#include <iostream>
#include <gtk/gtk.h>
#include "vista_pantalla_creacion_de_juego.h"
#include "ventana_exploracion_archivos.h"
#include "pantalla_seleccion_de_imperio.h"
#include "error.h"

class PantallaCreacionDeJuego : public VistaPantallaCreacionDeJuego {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_seleccione_mapa;
		GtkWidget* entrada_seleccione_mapa;
		GtkWidget* boton_examinar;
		GtkWidget* etiqueta_ingrese_puerto;
		GtkWidget* entrada_ingrese_puerto;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* hbox_entrada_mapa;
		GtkWidget* hbox_entrada_puerto;
		GtkWidget* hbox_botones;
		GtkWidget* vbox;

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_examinar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static void on_aceptar(GtkWidget* widget, gpointer data);

	public:			
		PantallaCreacionDeJuego(ContextoJuego* contexto);
		void mostrar_alerta(string mensaje);
		void cerrar();
		string solicitar_archivo(string descripcion);
		
		string get_ruta_mapa_seleccionado();
		void set_ruta_mapa_seleccionado(string valor);
		
		string get_puerto();
		void mostrar_seleccion_de_imperio();

};

#endif /* PANTALLA_CREACION_DE_JUEGO_H_ */
