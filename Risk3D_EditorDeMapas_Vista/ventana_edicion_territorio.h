#ifndef VENTANA_CREAR_TERRITORIO_H_
#define VENTANA_CREAR_TERRITORIO_H_

#include <gtk/gtk.h>
#include <glib.h>
#include "vista_edicion_territorio.h"
#include "utilidades_string.h"
#include "error.h"

class VentanaEdicionTerritorio : public VistaEdicionTerritorio {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_seleccione_continente;
		GtkWidget* menu_desplegable;
		GtkWidget* etiqueta_nombre_territorio;
		GtkWidget* etiqueta_coordenadas;
		GtkWidget* entrada_nombre_territorio;
		GList* lista_items_menu_desplegable;
		GtkWidget* etiqueta_x;
		GtkWidget* etiqueta_y;
		GtkWidget* entrada_x;
		GtkWidget* entrada_y;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* tabla_ventana;
		GtkWidget* tabla_botones;

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);

	public:
		VentanaEdicionTerritorio(ContextoEditor* contexto);
		~VentanaEdicionTerritorio();
		void cerrar();
		void set_coordenadas(int x, int y);
		int get_coordenada_x();
		int get_coordenada_y();
		string get_nombnre_continente();
		string get_nombre_territorio();
		void set_nombre_territorio(string nombre_territorio);
		void set_continentes(ContenedorContinentes* continentes);
		/* set_continentes sobrecargado por si se quiere utilizar algun continente por default... */
		void set_continentes(ContenedorContinentes* continentes, Continente* continente);
		void mostrar_alerta(string mensaje);
};

#endif /* VENTANA_EDICION_TERRITORIO_H_ */