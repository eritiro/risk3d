#include "icono_territorio.h"


IconoTerritorio::IconoTerritorio(Tropa* tropa, ControladorPantallaJuego* controlador, string archivo_icono, string archivo_icono_iluminado){
	this->controlador = controlador;
	this->archivo_icono_sin_iluminacion = archivo_icono;
	this->archivo_icono_con_iluminacion = archivo_icono_iluminado;
	/* Creo icono a mostrar sobre textura. */
	this->icono_event_box = gtk_event_box_new();
	this->tooltip = gtk_tooltips_new();
	this->tropa = tropa;
	this->iluminado = false;

	Territorio* territorio = tropa->get_territorio();

	/* Genero texto tooltip a mostrar... */
	string texto = territorio->get_nombre() + " (" + territorio->get_continente()->get_nombre() + ") " + '\n' 
				 + "Imperio: " + tropa->get_imperio()->get_nombre_emperador() + '\n'
				 + "Ejercitos: " + UtilidadesString::int_a_string(tropa->get_ejercitos());

	/* Seteo en el tooltips el nombre del territorio. */
	gtk_tooltips_set_tip(GTK_TOOLTIPS(this->tooltip), GTK_WIDGET(this->icono_event_box), texto.c_str(), NULL);
	gtk_tooltips_set_delay (this->tooltip, 0);

	g_signal_connect(G_OBJECT(this->get_widget()), "button_press_event", G_CALLBACK(on_icono_clicked), this);

	/* Seteo icono o imagen a utilizar... */
	this->imagen = gtk_image_new_from_file(archivo_icono.c_str());


	/* Organizo widgets a mostrar... */
	gtk_container_add(GTK_CONTAINER(this->icono_event_box), GTK_WIDGET(this->imagen));
	
	
	/* Muestro widgets...*/
	gtk_widget_show(this->imagen);
	gtk_widget_show(this->icono_event_box);
}


IconoTerritorio::~IconoTerritorio(){
	gtk_widget_destroy(this->icono_event_box);
}


GtkWidget* IconoTerritorio::get_widget(){
	return this->icono_event_box;
}


void IconoTerritorio::on_icono_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data){
	IconoTerritorio* icono = (IconoTerritorio*)data;
	icono->controlador->manejar_evento_territorio_seleccionado(icono->tropa->get_territorio());
}

Tropa* IconoTerritorio::get_tropa(){
	return this->tropa;
}

void IconoTerritorio::set_iluminacion(bool valor){
	if(this->iluminado == valor)
		return;

	this->iluminado = valor;

	gtk_widget_destroy(this->imagen);

	/* Seteo icono o imagen a utilizar... */
	if(this->iluminado)
		this->imagen = gtk_image_new_from_file(archivo_icono_con_iluminacion.c_str());
	else
		this->imagen = gtk_image_new_from_file(archivo_icono_sin_iluminacion.c_str());

	/* Organizo widgets a mostrar... */
	gtk_container_add(GTK_CONTAINER(this->icono_event_box), GTK_WIDGET(this->imagen));

	gtk_widget_show(imagen);
}