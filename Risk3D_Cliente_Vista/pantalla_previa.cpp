#include "pantalla_previa.h"
#include "utilidades_string.h"


using namespace std;

PantallaPrevia::PantallaPrevia(ContextoJuego* contexto/*, GtkWidget* ventana_padre*/) : VistaPantallaPrevia(contexto){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Risk 3D.");
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_resize(GTK_WINDOW(this->ventana), 600, 300);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);


	/* Creo boxes. */
	this->hbox_ventana_chat = gtk_hbox_new(FALSE, 0);
	this->hbox = gtk_hbox_new(FALSE, 0);
	this->vbox = gtk_vbox_new(FALSE, 0);

	
	/* Creo etiqueta. */
	this->etiqueta_chat = gtk_label_new("Risk 3D Chat.");

	/* Creo cuadro de texto para chat, barra de desplazamiento y organizo sus widgets. */
	this->ventana_chat = gtk_text_new(NULL, NULL);
	this->barra_desplazamiento_vertical = gtk_vscrollbar_new(GTK_TEXT(this->ventana_chat)->vadj);
	gtk_text_set_editable(GTK_TEXT(this->ventana_chat), FALSE);


	gtk_box_pack_start(GTK_BOX(this->hbox_ventana_chat), this->ventana_chat, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_ventana_chat), this->barra_desplazamiento_vertical, FALSE, FALSE, 0);

	/* Creo entrada de texto para chat y botones y organizo estos widgets. */
	this->entrada_chat = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(this->entrada_chat), 150);     

	this->boton_enviar = gtk_button_new_with_label("Enviar");
	this->boton_comenzar = gtk_button_new_with_label("Comenzar");
	
	gtk_box_pack_start(GTK_BOX(this->hbox), this->entrada_chat, TRUE, TRUE, 3);
	gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_enviar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_comenzar, FALSE, FALSE, 3);
	
		

	/* Organizo ventana. */
	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_chat, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->hbox_ventana_chat, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->hbox, FALSE, FALSE, 4);

	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox);

	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_enviar), "clicked", GTK_SIGNAL_FUNC(on_enviar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_comenzar), "clicked", GTK_SIGNAL_FUNC(on_comenzar), this);


	this->get_controlador().inicializar();

	gtk_widget_grab_focus(GTK_WIDGET(this->entrada_chat));
	
	gtk_window_set_modal(GTK_WINDOW(this->ventana), TRUE);

	/* Muestro ventana. */
	gtk_widget_show_all(this->ventana);

	/* Inicializo timeout. */
	this->id_temporizador = gtk_timeout_add(MILISEGUNDOS_POOLEO_CONTROLADOR, on_temporizador, this);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


void PantallaPrevia::mostrar_mensaje(string mensaje){
	mensaje += "\n";
	gtk_text_insert(GTK_TEXT(this->ventana_chat), NULL, &this->ventana_chat->style->black, NULL, mensaje.c_str(), -1);
	gtk_widget_grab_focus(GTK_WIDGET(this->entrada_chat));
}


void PantallaPrevia::mostrar_alerta(string mensaje){
	Error err(mensaje);
}


void PantallaPrevia::mostrar_chat(Imperio* imperio, string mensaje){
	GdkColormap* color_map = gdk_colormap_get_system();
	GdkColor color_rgb;
	Color color = VistaColorImperio(imperio->get_color()).get_color_rgb();
	color_rgb.red = 0xffff * color.get_rojo();
	color_rgb.green = 0xffff * color.get_verde();
	color_rgb.blue = 0xffff * color.get_azul();
	gdk_color_alloc(color_map, &color_rgb);

	string mensaje_chat = imperio->get_nombre_emperador() + " dice: " + mensaje + "\n";

	gtk_text_insert(GTK_TEXT(this->ventana_chat), NULL, &color_rgb, NULL, mensaje_chat.c_str(), -1);
}


void PantallaPrevia::mostrar_juego(){
	PantallaJuego pantalla(this->get_contexto());
	this->cerrar();
}

void PantallaPrevia::cerrar(){
	gtk_timeout_remove(this->id_temporizador);
	gtk_widget_destroy(this->ventana);
}


PantallaPrevia::~PantallaPrevia(){
	gtk_timeout_remove(this->id_temporizador);
}



/* Definicion de callbacks. */

gboolean PantallaPrevia::on_destruir_ventana(GtkWidget* widget, gpointer data){
	gtk_widget_destroy(widget);
	return FALSE;
}


void PantallaPrevia::on_enviar(GtkWidget* widget, gpointer data){
	PantallaPrevia* instancia = (PantallaPrevia*)data;
	const char* mensaje = gtk_entry_get_text(GTK_ENTRY(instancia->entrada_chat));
	string mensaje_str = string(mensaje);
	if (mensaje_str.compare("") != 0){
		instancia->get_controlador().manejar_evento_chat(mensaje_str);
		gtk_entry_set_text(GTK_ENTRY(instancia->entrada_chat), "");
	}
	gtk_widget_grab_focus(GTK_WIDGET(instancia->entrada_chat));
}


gint PantallaPrevia::on_temporizador(gpointer data){
	PantallaPrevia* instancia = (PantallaPrevia*)data;
	instancia->get_controlador().manejar_evento_temporizador();
	return TRUE;
}


void PantallaPrevia::on_comenzar(GtkWidget* widget, gpointer data){
	PantallaPrevia* instancia = (PantallaPrevia*)data;
	instancia->get_controlador().manejar_evento_comenzar_juego();
}
