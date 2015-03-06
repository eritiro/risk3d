#ifndef VENTANA_ADMINISTRACION_OBJETIVOS_H_
#define VENTANA_ADMINISTRACION_OBJETIVOS_H_

#include <gtk/gtk.h>
#include <glib.h>
#include <utility>
#include "vista_administrar_objetivos.h"
#include "utilidades_string.h"
#include "ventana_edicion_objetivo.h"
#include "requisito_de_ocupacion.h"
#include "error.h"

using std::pair;

class VentanaAdministracionObjetivos;

typedef pair<VentanaAdministracionObjetivos*, RequisitoDeOcupacion*> ParVentanaObjetivo;
typedef vector<ParVentanaObjetivo*> ContenedorParesVentanaObjetivo;
typedef ContenedorParesVentanaObjetivo::iterator IteradorParesVentanaObjetivo;


class VentanaAdministracionObjetivos : public VistaAdministrarObjetivos {
	private:
		GtkWidget* ventana;
		GtkWidget* etiqueta_nombre_objetivo;
		GtkWidget* boton_modificar;
		GtkWidget* boton_eliminar;
		GtkWidget* boton_agregar_nuevo;
		GtkWidget* boton_cancelar;
		GtkWidget* hbox;
		GtkWidget* hbox_botones;
		GtkWidget* vbox_principal;
		 
		ContenedorParesVentanaObjetivo contenedor_pares;

		static void on_destruir_ventana(GtkWidget* widget, gpointer data);
		static void on_agregar_nuevo(GtkWidget* widget, gpointer data);
		static void on_cancelar(GtkWidget* widget, gpointer data);
		static void on_modificar(GtkWidget* widget, gpointer data);
		static void on_eliminar(GtkWidget* widget, gpointer data);

	public:
		VentanaAdministracionObjetivos(ContextoEditor* contexto);
		~VentanaAdministracionObjetivos();
		void cerrar();
		void set_requisitos(ContenedorRequisitos contenedor_requisitos);
		void abrir_ventana_edicion_objetivo();
		void mostrar_mensaje_alerta(string mensaje);
		void actualizar(ContenedorRequisitos contenedor_requisitos);

};

#endif /* VENTANA_ADMINISTRACION_OBJETIVOS_H_ */