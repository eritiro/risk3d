#ifndef VENTANA_ELIMINAR_CONTINENTE_H_
#define VENTANA_ELIMINAR_CONTINENTE_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el pair es un template
// "asi de grande".
#pragma warning(disable:4786)

#include <gtk/gtk.h>
#include <glib.h>
#include <utility>
#include <vector>
#include "vista_eliminar_continente.h"


using std::pair;
using std::vector;

class VentanaEliminarContinente;

typedef pair<VentanaEliminarContinente*, string> Par;
typedef vector<Par*> ContenedorPares;
typedef ContenedorPares::iterator IteradorPares;

class VentanaEliminarContinente : public VistaEliminarContinente {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_seleccione_continente;
		GtkWidget* area_ventana_desplazamiento;
		GtkWidget* vbox_area_ventana_desplazamiento;
		GtkWidget* vbox;
		GtkWidget* tabla;
		GtkWidget* boton_check;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;

		ContenedorPares contenedor_pares;

		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_seleccionado(GtkWidget* widget, gpointer data);

		

	public:
		VentanaEliminarContinente(ContextoEditor* contexto);
		~VentanaEliminarContinente();
		void set_continentes(ContenedorContinentes* continentes);
		void cerrar();

};


#endif /* VENTANA_ELIMINAR_CONTINENTE_H_ */