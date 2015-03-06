#ifndef ICONO_TERRITORIO_ADYACENTE_H_
#define ICONO_TERRITORIO_ADYACENTE_H_

#include "icono_territorio.h"


class IconoTerritorioAdyacente : public IconoTerritorio {
	private:
		static void on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);

	public:
		IconoTerritorioAdyacente(Territorio* territorio, ControladorEditorDeMapa* controlador);
		~IconoTerritorioAdyacente();
};

#endif /* ICONO_TERRITORIO_ADYACENTE_H_ */