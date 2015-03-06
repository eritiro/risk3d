#ifndef VENTANA_CREAR_CONTINENTE_H_
#define VENTANA_CREAR_CONTINENTE_H_

#include <gtk/gtk.h>
#include "vista_crear_continente.h"
#include "error.h"

class VentanaCrearContinente : public VistaCrearContinente{
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_nombre;
		GtkWidget* etiqueta_bonus;
		GtkWidget* entrada_continente;
		GtkWidget* entrada_bonus;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* tabla;

		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static void on_destruir_ventana(GtkWidget* widget, gpointer data);

	public:
		VentanaCrearContinente(ContextoEditor* contexto);
		~VentanaCrearContinente();
		string get_nombre_continente();
		string get_bonus_continente();
		void cerrar();
		void mostrar_alerta(string mensaje);
};


#endif /* VENTANA_CREAR_CONTINENTE_H_ */