#include "icono_territorio_comun.h"


IconoTerritorioComun::IconoTerritorioComun(Territorio* territorio, ControladorEditorDeMapa* controlador) : IconoTerritorio(territorio, controlador){
	/* Seteo icono o imagen a utilizar... */
	this->imagen = gtk_image_new_from_file(ruta_icono_territorio_comun.c_str());


	/* Organizo widgets a mostrar... */
	gtk_container_add(GTK_CONTAINER(this->icono_event_box), GTK_WIDGET(this->imagen));
	
	
	/* Muestro widgets...*/
	gtk_widget_show(this->imagen);
	gtk_widget_show(this->icono_event_box);
}


IconoTerritorioComun::~IconoTerritorioComun(){
}