#ifndef AREA_DE_EDICION_H_
#define AREA_DE_EDICION_H_

#include <vector>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "textura.h"
#include "controlador_editor_de_mapa.h"
#include "icono_territorio_comun.h"
#include "icono_territorio_activo.h"
#include "icono_territorio_adyacente.h"

using std::vector;

typedef vector<IconoTerritorio*> ContenedorIconos;
typedef ContenedorIconos::iterator IteradorIconos;

class AreaDeEdicion {
	private:
		ControladorEditorDeMapa* controlador_editor_de_mapa;
		GtkWidget* event_box;
		Textura* textura;

		GtkWidget* ventana_desplazamiento;
		GtkWidget* layout;

		ContenedorIconos iconos;

		static void on_evento_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);
		void destruir_iconos();

	public:
		AreaDeEdicion(ControladorEditorDeMapa* controlador);
		~AreaDeEdicion();
		void set_textura(string ruta_textura);
		GtkWidget* get_widget();
		void ocultar_textura();
		void refrescar_mapa(Mapa* mapa);		
		void refrescar_mapa(Mapa* mapa, Territorio* territorio_seleccionado);

};


#endif /* AREA_DE_EDICION_H_ */
