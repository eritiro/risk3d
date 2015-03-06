#ifndef MENU_VENTANA_PRINCIPAL_H_
#define MENU_VENTANA_PRINCIPAL_H_

#pragma warning(disable:4786)

#include <gtk/gtk.h>
#include "controlador_editor_de_mapa.h"



class MenuVentanaPrincipal {
	private:
		ControladorEditorDeMapa* controlador;

		GtkWidget* barra_menu;

		GtkWidget* menu_editor;
		GtkWidget* submenu_editor;
		GtkWidget* item_editor_nuevo_mapa;
		GtkWidget* item_editor_abrir_mapa;
		GtkWidget* item_editor_guardar_mapa;
		GtkWidget* item_editor_guardar_como_mapa;
		GtkWidget* item_editor_cerrar_mapa;
		GtkWidget* item_editor_salir;

		GtkWidget* menu_continente;
		GtkWidget* submenu_continente;
		GtkWidget* item_continente_crear;
		GtkWidget* item_continente_modificar;
		GtkWidget* item_continente_eliminar;

		GtkWidget* menu_territorio;
		GtkWidget* submenu_territorio;
		GtkWidget* item_territorio_editar;
		GtkWidget* item_territorio_eliminar;
		GtkWidget* item_territorio_adyacencias;

		GtkWidget* menu_ayuda;
		GtkWidget* submenu_ayuda;
		GtkWidget* item_ayuda_web;
		GtkWidget* item_ayuda_acercade;

		GtkWidget* menu_objetivos;
		GtkWidget* submenu_objetivos;
		GtkWidget* item_administrar_objetivos;
				

		void crear_menu_editor();
		void crear_menu_continente();
		void crear_menu_territorio();
		void crear_menu_objetivos();
		void crear_menu_ayuda();

		void mostrar_menu_editor();
		void mostrar_menu_continente();
		void mostrar_menu_territorio();
		void mostrar_menu_objetivos();
		void mostrar_menu_ayuda();
		
		
		static void on_nuevo_mapa(GtkWidget* widget, gpointer data);
		static void on_abrir_mapa(GtkWidget* widget, gpointer data);
		static void on_cerrar_mapa(GtkWidget* widget, gpointer data);
		static void on_guardar_mapa(GtkWidget* widget, gpointer data);
		static void on_guardar_como_mapa(GtkWidget* widget, gpointer data);
		static void on_editor_salir(GtkWidget* widget, gpointer data);
		
		static void on_crear_continente(GtkWidget* widget, gpointer data);
		static void on_modificar_continente(GtkWidget* widget, gpointer data);
		static void on_eliminar_continente(GtkWidget* widget, gpointer data);

		static void on_editar_territorio(GtkWidget* widget, gpointer data);
		static void on_editar_adyacencias(GtkWidget* widget, gpointer data);
		static void on_eliminar_territorio(GtkWidget* widget, gpointer data);

		static void on_objetivos(GtkWidget* widget, gpointer data);
		static void on_acerca_de(GtkWidget* widget, gpointer data);


	public:
		MenuVentanaPrincipal(ControladorEditorDeMapa* controlador);
		~MenuVentanaPrincipal();
		GtkWidget* get_widget();
		void mostrar_barra_menu();
		
};

#endif /* MENU_VENTANA_PRINCIPAL_H_ */