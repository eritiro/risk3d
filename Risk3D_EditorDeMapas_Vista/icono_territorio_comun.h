#ifndef ICONO_TERRITORIO_COMUN_H_
#define ICONO_TERRITORIO_COMUN_H_

#include "icono_territorio.h"


class IconoTerritorioComun : public IconoTerritorio {
	private:
		static void on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data);

	public:
		IconoTerritorioComun(Territorio* territorio, ControladorEditorDeMapa* controlador);
		~IconoTerritorioComun();
};

#endif /* ICONO_TERRITORIO_COMUN_H_ */