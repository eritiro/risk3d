#ifndef VENTANA_PREGUNTA_SI_NO_H_
#define VENTANA_PREGUNTA_SI_NO_H_

#include <gtk/gtk.h>
#include <string>

using namespace std;

class VentanaPreguntaSiNo {
	private:
		GtkWidget* ventana;
		GtkWidget* pregunta;
		GtkWidget* boton;
		bool respuesta;

		static void on_si(GtkWidget* widget, gpointer data);
		static void on_no(GtkWidget* widget, gpointer data);

	public:
		VentanaPreguntaSiNo(string pregunta);
		~VentanaPreguntaSiNo();
		bool elegir_respuesta();

};

#endif /* VENTANA_PREGUNTA_SI_NO_H_ */