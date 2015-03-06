#ifndef AREA_DE_JUEGO_H_
#define AREA_DE_JUEGO_H_

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "info_juego.h"

class AreaDeJuego {
	public:
		AreaDeJuego(){
		}
		virtual ~AreaDeJuego(){
		}
		virtual GtkWidget* get_widget() = 0;
		virtual void actualizar(InfoJuego* info) = 0;
		virtual void resaltar_territorios_adyacentes(Territorio* territorio) = 0;
		virtual void quitar_resaltado_de_territorios() = 0;
};

#endif /* AREA_DE_JUEGO_H_ */
