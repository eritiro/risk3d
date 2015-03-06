#include "icono_territorio.h"


IconoTerritorio::IconoTerritorio(Territorio* territorio, ControladorEditorDeMapa* controlador){
	this->controlador = controlador;
	
	/* Creo icono a mostrar sobre textura. */
	this->icono_event_box = gtk_event_box_new();
	this->tooltip = gtk_tooltips_new();
	this->territorio = territorio;

	/* Genero texto tooltip a mostrar... */
	string texto = "Nombre: " + territorio->get_nombre() + '\n' 
				 + "X: " + UtilidadesString::int_a_string(territorio->get_posicion().get_x()) + "  Y: " + UtilidadesString::int_a_string(territorio->get_posicion().get_y());

	/* Seteo en el tooltips el nombre del territorio. */
	gtk_tooltips_set_tip(GTK_TOOLTIPS(this->tooltip), GTK_WIDGET(this->icono_event_box), texto.c_str(), NULL);
	gtk_tooltips_set_delay (this->tooltip, 0);

	g_signal_connect(G_OBJECT(this->get_widget()), "button_press_event", G_CALLBACK(on_icono_clicked), this);

}


IconoTerritorio::~IconoTerritorio(){
	gtk_widget_destroy(this->icono_event_box);
}


GtkWidget* IconoTerritorio::get_widget(){
	return this->icono_event_box;
}


void IconoTerritorio::on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data){
	IconoTerritorio* icono = (IconoTerritorio*)data;
	icono->controlador->manejar_evento_edicion(icono->territorio);
}
