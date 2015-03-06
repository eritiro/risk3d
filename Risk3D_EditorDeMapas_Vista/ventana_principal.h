#ifndef VENTANA_PRINCIPAL_H_
#define VENTANA_PRINCIPAL_H_

#pragma warning(disable:4786)


#include <gtk/gtk.h>
#include <string>
#include "menu_ventana_principal.h"
#include "barra_de_estado.h"
#include "error.h"
#include "area_de_edicion.h"
#include "vista_editor_de_mapa.h"
#include "controlador_editor_de_mapa.h"
#include "ventana_exploracion_archivos.h"
#include "ventana_crear_continente.h"
#include "ventana_modificar_continente.h"
#include "ventana_eliminar_continente.h"
#include "ventana_edicion_territorio.h"
#include "ventana_administracion_objetivos.h"
#include "ventana_acerca_de.h"
#include "ventana_pregunta_si_no.h"

using namespace std;

class VentanaPrincipal : public VistaEditorDeMapa {
	private:
		GtkWidget* ventana;
		GtkWidget* vbox;
		MenuVentanaPrincipal* barra_menu;
		BarraDeEstado* barra_de_estado;
		AreaDeEdicion* area_de_edicion;

		static void on_destruir_ventana_principal(GtkWidget* widget, gpointer data);

	public:
		VentanaPrincipal(ContextoEditor* contexto);
		~VentanaPrincipal();
		void crear();
		void mostrar();
		void mostrar_mensaje_barra_estado(string mensaje);
		void mostrar_mensaje_alerta(string mensaje);
		void destruir_ventana_principal();
		string solicitar_archivo(string descripcion);
		
		void abrir_ventana_crear_continente();
		void abrir_ventana_modificar_continente();
		void abrir_ventana_eliminar_continente();

		
		void abrir_ventana_edicion_territorio();
		
		void mostrar_textura(string archivo);
		void ocultar_textura();
		void refrescar_mapa(Mapa* mapa);
		void refrescar_mapa(Mapa* mapa, Territorio* territorio_seleccionado);

		void abrir_ventana_administrar_objetivos();
		void abrir_ventana_acerca_de();

		bool elegir_respuesta(string descripcion);

};

#endif /* VENTANA_PRINCIPAL_H_ */
