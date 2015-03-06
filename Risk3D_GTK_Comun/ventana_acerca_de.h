#ifndef VENTANA_ACERCA_DE_H_
#define VENTANA_ACERCA_DE_H_

#include <gtk/gtk.h>
#include <string>

using std::string;


class VentanaAcercaDe {
	private:
		GtkWidget* ventana;
		GtkWidget* frame;
		GtkWidget* etiqueta_texto;

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);

	public:
		VentanaAcercaDe();
		~VentanaAcercaDe();

}; 


#endif /* VENTANA_ACERCA_DE_H_ */