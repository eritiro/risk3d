#ifndef ICONO_TERRITORIO_ACTIVO_H_
#define ICONO_TERRITORIO_ACTIVO_H_

#include "icono_territorio.h"


class IconoTerritorioActivo : public IconoTerritorio {
	private:
		static void on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);

	public:
		IconoTerritorioActivo(Territorio* territorio, ControladorEditorDeMapa* controlador);
		~IconoTerritorioActivo();
};

#endif /* ICONO_TERRITORIO_ACTIVO_H_ */