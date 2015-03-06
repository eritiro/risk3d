#ifndef VENTANA_MODIFICAR_CONTINENTE_H_
#define VENTANA_MODIFICAR_CONTINENTE_H_

#include <gtk/gtk.h>
#include <glib.h>
#include <stdio.h>
#include <string>
#include "utilidades_string.h"
#include "vista_modificar_continente.h"
#include "error.h"

using namespace std;


class VentanaModificarContinente : public VistaModificarContinente {
	private:
		GtkWidget* ventana;
		GtkWidget* menu_desplegable;
		GtkWidget* etiqueta_seleccione_continente;
		GtkWidget* etiqueta_nuevo_nombre;
		GtkWidget* etiqueta_nuevo_bonus;
		GtkWidget* entrada_nuevo_nombre;
		GtkWidget* entrada_nuevo_bonus;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* boton_cargar_informacion_continente;
		GtkWidget* tabla;
		GList* lista_items_menu_desplegable;

		static void on_cargar_informacion_continente(GtkWidget* widget, gpointer data);
		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		

	public:
		VentanaModificarContinente(ContextoEditor* contexto);
		~VentanaModificarContinente();
		string get_nombre_continente_seleccionado();
		void set_continentes(ContenedorContinentes* continentes);
		void set_continente_seleccionado(ContenedorContinentes* continentes, string nombre_continente_seleccionado);
		string get_nuevo_nombre_continente();
		string get_nuevo_bonus_continente();
		void mostrar_alerta(string mensaje);
		void cerrar();

};


#endif /* VENTANA_MODIFICAR_CONTINENTE_H_ */