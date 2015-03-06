#ifndef AREA_DE_JUEGO_2D_H_
#define AREA_DE_JUEGO_2D_H_

#include "area_de_juego.h"
#include "controlador_pantalla_juego.h"
#include "constantes_vista.h"
#include "icono_territorio.h"


using std::vector;

typedef vector<IconoTerritorio*> ContenedorIconos;
typedef ContenedorIconos::iterator IteradorIconos;

class AreaDeJuego2D : public AreaDeJuego {
	private:
		ControladorPantallaJuego& controlador;
		GdkPixbuf* pixbuf;
		GtkWidget* imagen;
		GtkWidget* layout;
		GtkWidget* caja_de_eventos;
		bool imagen_activa;
		int ancho_original;
		int alto_original;
		ContenedorIconos iconos;

		
		void mostrar_imagen(string ruta_archivo);
		void destruir_iconos();
		void dibujar_iconos(InfoJuego* info);
		void dibujar_icono(Tropa*, Coordenada posicion, ColorImperio color);
		static void on_evento_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);

	public:
		AreaDeJuego2D(ControladorPantallaJuego& controlador);
		~AreaDeJuego2D();
		GtkWidget* get_widget();
		void actualizar(InfoJuego* info);
		void resaltar_territorios_adyacentes(Territorio* territorio);
		void quitar_resaltado_de_territorios();
};

#endif /* AREA_DE_JUEGO_2D_H_ */
