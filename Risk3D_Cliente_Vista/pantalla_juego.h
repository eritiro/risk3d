#ifndef PANTALLA_JUEGO_H_
#define PANTALLA_JUEGO_H_

#define GTK_ENABLE_BROKEN

#include <iostream>
#include <gtk/gtk.h>
#include <gtk/gtkgl.h>
#include <gdk/gdkkeysyms.h>
#include <gdk/gdk.h>
#include <windows.h>
#include "vista_pantalla_juego.h"
#include "barra_de_estado.h"
#include "error.h"
#include "vista_color_imperio.h"
#include "constantes_vista.h"
#include "area_de_juego.h"
#include "ventana_pregunta.h"
#include "ventana_de_informacion.h"
#include "ventana_mostrar_objetivo.h"
#include "ventana_acerca_de.h"



class PantallaJuego : public VistaPantallaJuego {
	private:
		GtkWidget* ventana;
		GtkWidget* caja_eventos;
		GtkWidget* contenedor_area_de_juego;
		GtkWidget* ventana_chat;
		GtkWidget* entrada_chat;
		GtkWidget* boton_enviar;
		GtkWidget* boton_reforzar;
		GtkWidget* boton_atacar;
		GtkWidget* boton_reagrupar;
		GtkWidget* boton_fin_de_turno;
		GtkWidget* boton_acerca_de;
		GtkWidget* boton_cambiar_modo_vista;
		GtkWidget* boton_mostrar_objetivo;
		GtkWidget* barra_desplazamiento_vertical_chat;
		GtkWidget* vbox_principal;
		GtkWidget* vbox_botones;
		GtkWidget* hbox_botones_area_dibujo;
		GtkWidget* hbox_ventana_chat;
		GtkWidget* vbox_chat;
		GtkWidget* hbox_chat_info;
		GtkWidget* hbox_entrada_chat;
		BarraDeEstado barra_de_estado;
		AreaDeJuego* area_de_juego;
		VentanaDeInformacion* ventana_de_informacion;
		int id_temporizador;
		bool mostrando_area_de_juego_2d;
		
		static void on_acerca_de(GtkWidget* widget, gpointer data);
		static void on_atacar(GtkWidget* widget, gpointer data);
		static void on_cambiar_modo_vista(GtkWidget* widget, gpointer data);
		static void on_enviar(GtkWidget* widget, gpointer data);
		static void on_fin_de_turno(GtkWidget* widget, gpointer data);
		static void on_reagrupar(GtkWidget* widget, gpointer data);
		static void on_reforzar(GtkWidget* widget, gpointer data);
		static gint on_temporizador(gpointer data);
		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_mostrar_objetivo(GtkWidget* widget, gpointer data);

	public:			
		PantallaJuego(ContextoJuego* contexto);
		~PantallaJuego();

		void mostrar_instruccion(string mensaje);
		void mostrar_mensaje_de_sistema(string mensaje);
		void mostrar_mensaje_de_chat(Imperio* imperio, string mensaje);
		void mostrar_alerta(string mensaje);
		void mostrar_batalla(Territorio* agresor, int agresores_caidos, 
									 Territorio* agredido, int defensores_caidos);
		string preguntar(string pregunta);
		void actualizar(InfoJuego* info, Imperio* imperio);
		void resaltar_territorios_adyacentes(Territorio* territorio);
		void quitar_resaltado_de_territorios();
		void cerrar();
		void abrir_ventana_acerca_de();

		void cambiar_modo_vista(InfoJuego* info);
		void abrir_ventana_mostrar_objetivo(string objetivo);
};

#endif /* PANTALLA_JUEGO_H_ */
