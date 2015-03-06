#ifndef VENTANA_MOSTRAR_OBJETIVO_H_
#define VENTANA_MOSTRAR_OBJETIVO_H_

#include <gtk/gtk.h>
#include <string>

using std::string;

class VentanaMostrarObjetivo {
	private:
		GtkWidget* ventana;
		GtkWidget* boton_cerrar;
		GtkWidget* frame;
		GtkWidget* hbox;
		GtkWidget* vbox;
		GtkWidget* etiqueta_objetivo;

		static void on_cerrar(GtkWidget* widget, gpointer data);
		static void on_destruir_ventana(GtkWidget* widget, gpointer data);

	public:
		VentanaMostrarObjetivo(string objetivo);
		~VentanaMostrarObjetivo();
};


#endif /* VENTANA_MOSTRAR_OBJETIVO_H_ */

