#ifndef VENTANA_EDICION_OBJETIVO_H_
#define VENTANA_EDICION_OBJETIVO_H_

#include <gtk/gtk.h>
#include <map>
#include "vista_editar_objetivo.h"
#include "error.h"
#include "macros.h"

typedef std::map<int,GtkWidget*> TablaContinenteValor;
typedef TablaContinenteValor::iterator IteradorTablaContinenteValor;

class VentanaEdicionObjetivo : public VistaEditarObjetivo {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_continente;
		GtkWidget* rango_seleccion;
		GtkObject* ajuste_rango_seleccion;
		GtkWidget* boton_aceptar;
		GtkWidget* boton_cancelar;
		GtkWidget* vbox_principal;
		GtkWidget* hbox_botones;
		GtkWidget* vbox_continentes;
		GtkWidget* hbox;

		TablaContinenteValor tabla_continente_valor;

		void set_continente(Continente* continente, int valor);

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_aceptar(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);

	public:
		VentanaEdicionObjetivo(ContextoEditor* contexto_editor);
		~VentanaEdicionObjetivo();
		void cerrar();
		void set_continentes_default(ContenedorContinentes* contenedor_continentes);
		void mostrar_mensaje_alerta(string mensaje);
		void agregar_continente_valor(Continente* continente, int cantidad_territorios_seleccionado);
		int get_valor_por_continente(Continente* continente);
};

#endif /* VENTANA_EDICION_OBJETIVO_H_ */