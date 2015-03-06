#ifndef VENTANA_PREGUNTA_H_
#define VENTANA_PREGUNTA_H_

#include <gtk/gtk.h>
#include <string>

using std::string;

class VentanaPregunta {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_pregunta;
		GtkWidget* entrada_respuesta;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* vbox;
		GtkWidget* hbox;
		string respuesta;

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);

	public:
		VentanaPregunta(string pregunta);
		~VentanaPregunta();
		string get_respuesta();

};


#endif /* VENTANA_PREGUNTA_H_ */