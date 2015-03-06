#include "pantalla_principal.h"
#include "pantalla_creacion_de_juego.h"
#include "pantalla_seleccion_de_servidor.h"


PantallaPrincipal::PantallaPrincipal(ContextoJuego* contexto) : VistaPantallaPrincipal(contexto){
	this->get_controlador().inicializar();

	/* Creo ventana principal */
	this->ventana_principal = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(this->ventana_principal), "Risk 3D.");
	gtk_window_resize(GTK_WINDOW(this->ventana_principal), 300, 300);
	gtk_window_set_position(GTK_WINDOW(this->ventana_principal), GTK_WIN_POS_CENTER);
	
	/* Creo botones */
	this->boton_crear_juego = gtk_button_new_with_label("Crear un juego.");
	this->boton_unirse_a_juego = gtk_button_new_with_label("Unirse a un juego.");
	this->boton_salir = gtk_button_new_with_label("Salir de Risk 3D.");

	/* Creo vertical box y organizo widgets */
	this->vbox = gtk_vbox_new(TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->boton_crear_juego), FALSE, TRUE, 20);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->boton_unirse_a_juego), FALSE, TRUE, 20);
	gtk_box_pack_start(GTK_BOX(this->vbox), GTK_WIDGET(this->boton_salir), FALSE, TRUE, 20);

	gtk_container_set_border_width(GTK_CONTAINER(this->ventana_principal), 20);
	gtk_container_add(GTK_CONTAINER(this->ventana_principal), this->vbox);


	/* Callbacks */
	gtk_signal_connect(GTK_OBJECT(this->ventana_principal), "destroy", GTK_SIGNAL_FUNC(on_destruir_ventana_principal), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_crear_juego), "clicked", GTK_SIGNAL_FUNC(on_crear_juego), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_unirse_a_juego), "clicked", GTK_SIGNAL_FUNC(on_unirse_a_juego), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_salir), "clicked", GTK_SIGNAL_FUNC(on_salir), this);
	

	/* Muestro widgets */
	gtk_widget_show_all(this->ventana_principal);

}


void PantallaPrincipal::abrir_ventana_crear_juego(){
	PantallaCreacionDeJuego pantalla_creacion_de_juego(this->get_contexto());
}


void PantallaPrincipal::abrir_ventana_seleccion_servidor(){
	PantallaSeleccionDeServidor pantalla_seleccion_de_servidor(this->get_contexto());
}


/*
void PantallaPrincipal::mostrar_menu_seleccion_servidor(){
	PantallaSeleccionDeServidor pantalla_seleccion_de_servidor(this->get_contexto());
	pantalla_seleccion_de_servidor.mostrar();
}
*/



void PantallaPrincipal::cerrar(){
	gtk_main_quit();
}



/* Definicion de callbacks. */

void PantallaPrincipal::on_destruir_ventana_principal(GtkWidget* widget, gpointer data){
	PantallaPrincipal* instancia = (PantallaPrincipal*)data;
	instancia->get_controlador().manejar_evento_destruir_ventana_principal();
}


void PantallaPrincipal::on_crear_juego(GtkWidget* widget, gpointer data){
	PantallaPrincipal* instancia = (PantallaPrincipal*)data;
	instancia->get_controlador().manejar_evento_crear_juego();
}


void PantallaPrincipal::on_unirse_a_juego(GtkWidget* widget, gpointer data){
	PantallaPrincipal* instancia = (PantallaPrincipal*)data;
	instancia->get_controlador().manejar_evento_unirse_a_juego();
}


void PantallaPrincipal::on_salir(GtkWidget* widget, gpointer data){
	PantallaPrincipal* instancia = (PantallaPrincipal*)data;
	instancia->get_controlador().manejar_evento_salir();
}