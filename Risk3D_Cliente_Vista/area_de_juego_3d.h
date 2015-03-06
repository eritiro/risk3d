#ifndef AREA_DE_JUEGO_3D_H_
#define AREA_DE_JUEGO_3D_H_

#include <math.h>
#include <gtk/gtk.h>
#include <gtk/gtkgl.h>
#include <gdk/gdkgl.h>
#include "controlador_pantalla_juego.h"
#include "area_de_juego.h"
#include "constantes_vista.h"
#include "constantes_cliente.h"
#include "math3d.h"
#include "ciudad.h"
#include "vista_color_imperio.h"

// no se xq pero si los pones arriba de "controlador_pantalla_juego.h" rompe la compilacion :S
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <vector>

typedef std::vector<Ciudad*> ContenedorCiudades;
typedef ContenedorCiudades::iterator IteradorCiudades; 


class AreaDeJuego3D : public AreaDeJuego {
	private:
		ControladorPantallaJuego& controlador;
		bool imagen_activa;

		GtkWidget* vbox;
		GtkWidget* hbox;

		GtkWidget* event_box;
		GtkWidget* drawing_area;
		
		GtkWidget* boton_izquierda;
		GtkWidget* boton_derecha;
		GtkWidget* boton_acercar;
		GtkWidget* boton_alejar;

		GLUquadric* esfera;
		GLUquadric* ciudadQuad;
		GLUquadric* tapaQuad;
	
		Point3 viewpoint;
		ContenedorCiudades ciudades;

		unsigned int texture;

		float alpha;
		float dist;

		int ancho_original;
		int alto_original;

		void crear_widget_opengl();

		static void on_izquierda_presionada(GtkWidget* widget, gpointer data);
		static void on_derecha_presionada(GtkWidget* widget, gpointer data);
		static void on_acercar_presionado(GtkWidget* widget, gpointer data);
		static void on_alejar_presionado(GtkWidget* widget, gpointer data);

		static void on_click(GtkWidget* widget, GdkEventButton* evento, gpointer data);
		static gboolean expose_event(GtkWidget* widget, GdkEventExpose* event, gpointer data);
		static void realize (GtkWidget* widget, gpointer data);
		static gboolean configure_event(GtkWidget* widget, GdkEventConfigure* event, gpointer data);

		void cargar_textura();
		AUX_RGBImageRec* AreaDeJuego3D::leer_textura(char* filename);
		void actualizar_posicion_vista();
		void actualizar_ciudades(InfoJuego* info);
		void refrescar();
	public:
		AreaDeJuego3D(ControladorPantallaJuego& controlador);
		~AreaDeJuego3D();
		GtkWidget* get_widget();
		void actualizar(InfoJuego* info);
		void resaltar_territorios_adyacentes(Territorio* territorio);
		void quitar_resaltado_de_territorios();
};

#endif /* AREA_DE_JUEGO_3D_H_ */
