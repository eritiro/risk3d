#include "pantalla_juego.h"
#include "area_de_juego_2d.h"
#include "area_de_juego_3d.h"


PantallaJuego::PantallaJuego(ContextoJuego* contexto) : VistaPantallaJuego(contexto){
	// Creo ventana principal. 
	this->ventana = gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Risk 3D.");
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);


	this->contenedor_area_de_juego = gtk_layout_new(NULL, NULL);
	gtk_layout_set_size(GTK_LAYOUT(this->contenedor_area_de_juego), ANCHO_AREA_DE_JUEGO, ALTO_AREA_DE_JUEGO);
	gtk_widget_set_size_request(this->contenedor_area_de_juego, ANCHO_AREA_DE_JUEGO, ALTO_AREA_DE_JUEGO);

	this->area_de_juego = new AreaDeJuego3D(this->get_controlador());
	gtk_container_add(GTK_CONTAINER(this->contenedor_area_de_juego), this->area_de_juego->get_widget());
	this->mostrando_area_de_juego_2d = false;

	// Creo botones. 
	this->boton_atacar = gtk_button_new_with_label("Atacar");
	this->boton_enviar = gtk_button_new_with_label("Enviar");
	this->boton_fin_de_turno = gtk_button_new_with_label("Fin de Turno");
	this->boton_reagrupar = gtk_button_new_with_label("Reagrupar");
	this->boton_reforzar = gtk_button_new_with_label("Reforzar");
	this->boton_acerca_de = gtk_button_new_with_label("Acerca de...");
	this->boton_cambiar_modo_vista = gtk_button_new_with_label("Cambiar Modo Mapa");
	this->boton_mostrar_objetivo = gtk_button_new_with_label("Mostrar Objetivo");
	
	
	// Creo ventana de chat y entrada de texto de chat. 
	this->ventana_chat = gtk_text_new(NULL, NULL);
	gtk_widget_set_size_request (this->ventana_chat, 680, 100);
	this->barra_desplazamiento_vertical_chat = gtk_vscrollbar_new(GTK_TEXT(this->ventana_chat)->vadj);
	gtk_text_set_editable(GTK_TEXT(this->ventana_chat), FALSE);

	this->entrada_chat = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(this->entrada_chat), 150); 
	

	// Creo boxes. 
	this->hbox_ventana_chat = gtk_hbox_new(FALSE, 0);
	this->vbox_chat = gtk_vbox_new(FALSE, 0);
	this->hbox_entrada_chat = gtk_hbox_new(FALSE, 0);
	this->vbox_botones = gtk_vbox_new(FALSE, 0);
	this->hbox_botones_area_dibujo = gtk_hbox_new(FALSE, 0);
	this->vbox_principal = gtk_vbox_new(FALSE, 0);
	this->hbox_chat_info = gtk_hbox_new(FALSE, 0);
	

	// Organizo widgets ventana chat. 
	gtk_box_pack_start(GTK_BOX(this->hbox_ventana_chat), this->ventana_chat, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(this->hbox_ventana_chat), this->barra_desplazamiento_vertical_chat, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_chat), this->hbox_ventana_chat, TRUE, TRUE, 0); //FF
	gtk_box_pack_start(GTK_BOX(this->hbox_entrada_chat), this->entrada_chat, TRUE, TRUE, 4);
	gtk_box_pack_start(GTK_BOX(this->hbox_entrada_chat), this->boton_enviar, FALSE, FALSE, 2);
	gtk_box_pack_start(GTK_BOX(this->vbox_chat), this->hbox_entrada_chat, FALSE, FALSE, 2);

	// Organizo widgets botones.
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_reforzar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_atacar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_reagrupar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_fin_de_turno, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_cambiar_modo_vista, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_mostrar_objetivo, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_botones), this->boton_acerca_de, TRUE, TRUE, 0);

	
	/* Ventana de informacion. */
	this->ventana_de_informacion = new VentanaDeInformacion();
	
	
	// Organizo widgets area de dibujo de open gl y botones.
	gtk_box_pack_start(GTK_BOX(this->hbox_botones_area_dibujo), this->contenedor_area_de_juego, FALSE, FALSE, 0);
	//gtk_box_pack_start(GTK_BOX(this->hbox_botones_area_dibujo), this->area_de_juego->get_widget(), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_botones_area_dibujo), this->vbox_botones, TRUE, TRUE, 0);
	
	
	gtk_box_pack_start(GTK_BOX(this->hbox_chat_info), this->vbox_chat, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_chat_info), this->ventana_de_informacion->get_widget(), TRUE, TRUE, 3);


	// Organizo sub boxes en el box principal. 
	gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->hbox_botones_area_dibujo, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->hbox_chat_info, TRUE, TRUE, 2);

	/* Agrego barra de estado. */
	this->barra_de_estado.crear();
	gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->barra_de_estado.get_widget(), TRUE, TRUE, 0);

	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox_principal);

	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->boton_acerca_de), "clicked", GTK_SIGNAL_FUNC(on_acerca_de), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_atacar), "clicked", GTK_SIGNAL_FUNC(on_atacar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cambiar_modo_vista), "clicked", GTK_SIGNAL_FUNC(on_cambiar_modo_vista), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_enviar), "clicked", GTK_SIGNAL_FUNC(on_enviar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_fin_de_turno), "clicked", GTK_SIGNAL_FUNC(on_fin_de_turno), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_reagrupar), "clicked", GTK_SIGNAL_FUNC(on_reagrupar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_reforzar), "clicked", GTK_SIGNAL_FUNC(on_reforzar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_mostrar_objetivo), "clicked", GTK_SIGNAL_FUNC(on_mostrar_objetivo), this);
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	


	this->barra_de_estado.mostrar_mensaje(this->barra_de_estado.get_id_contexto("PantallaPrincipalJuego"),"Risk 3D.");


	// Inicializo controlador. 
	this->get_controlador().inicializar();

	// Gtk redibuja si alguno de sus hijos se modifico.
	gtk_container_set_reallocate_redraws(GTK_CONTAINER(this->ventana), TRUE);


	// Muestro widgets.
	gtk_window_set_modal(GTK_WINDOW(this->ventana), TRUE);
	gtk_widget_show_all(this->ventana);

	/* Inicializo timeout. */
	this->id_temporizador = gtk_timeout_add(MILISEGUNDOS_POOLEO_CONTROLADOR, on_temporizador, this);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


PantallaJuego::~PantallaJuego(){
	gtk_timeout_remove(this->id_temporizador);
	delete this->area_de_juego;
	delete this->ventana_de_informacion;
}


void PantallaJuego::mostrar_instruccion(string mensaje){
	this->barra_de_estado.mostrar_mensaje(this->barra_de_estado.get_id_contexto("MostrarInstruccion"), mensaje);
}


void PantallaJuego::mostrar_mensaje_de_sistema(string mensaje){
	mensaje += "\n";
	gtk_text_insert(GTK_TEXT(this->ventana_chat), NULL, &this->ventana_chat->style->black, NULL, mensaje.c_str(), -1);
}


void PantallaJuego::mostrar_mensaje_de_chat(Imperio* imperio, string mensaje){
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


void PantallaJuego::mostrar_alerta(string mensaje){
	Error err(mensaje);
}


void PantallaJuego::mostrar_batalla(Territorio* agresor, int agresores_caidos, 
									Territorio* agredido, int defensores_caidos){
}


string PantallaJuego::preguntar(string pregunta){
	VentanaPregunta ventana_pregunta(pregunta);
	return ventana_pregunta.get_respuesta();
}


void PantallaJuego::actualizar(InfoJuego* info, Imperio* imperio){
	string titulo = "Risk 3D - Emperador " + imperio->get_nombre_emperador();
	gtk_window_set_title(GTK_WINDOW(this->ventana), titulo.c_str());
	this->area_de_juego->actualizar(info);
	this->ventana_de_informacion->actualizar(imperio);
	
}

void PantallaJuego::resaltar_territorios_adyacentes(Territorio* territorio){
	this->area_de_juego->resaltar_territorios_adyacentes(territorio);
}

void PantallaJuego::quitar_resaltado_de_territorios(){
	this->area_de_juego->quitar_resaltado_de_territorios();
}

void PantallaJuego::cerrar(){
	gtk_widget_destroy(this->ventana);
}


void PantallaJuego::abrir_ventana_acerca_de(){
	VentanaAcercaDe ventana_acerca_de; 
}


void PantallaJuego::cambiar_modo_vista(InfoJuego* info){

	gtk_widget_destroy(this->area_de_juego->get_widget());
	delete(this->area_de_juego);
	
	if (this->mostrando_area_de_juego_2d)
		this->area_de_juego = new AreaDeJuego3D(this->get_controlador());
	else 
		this->area_de_juego = new AreaDeJuego2D(this->get_controlador());
	
	gtk_container_add(GTK_CONTAINER(this->contenedor_area_de_juego), this->area_de_juego->get_widget());
	this->mostrando_area_de_juego_2d = !this->mostrando_area_de_juego_2d;
	this->area_de_juego->actualizar(info);
}


void PantallaJuego::abrir_ventana_mostrar_objetivo(string objetivo){
	VentanaMostrarObjetivo ventana_mostrar_objetivo(objetivo);
}


/* Definicion de callbacks. */

void PantallaJuego::on_acerca_de(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_mostrar_acerca_de();
}
		
void PantallaJuego::on_atacar(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_atacar();
}


void PantallaJuego::on_cambiar_modo_vista(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_cambiar_modo_vista();
}


void PantallaJuego::on_enviar(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	const char* mensaje = gtk_entry_get_text(GTK_ENTRY(instancia->entrada_chat));
	string mensaje_str = string(mensaje);
	if (mensaje_str.compare("") != 0){
		instancia->get_controlador().manejar_evento_chat(mensaje_str);
		gtk_entry_set_text(GTK_ENTRY(instancia->entrada_chat), "");
	}
}


void PantallaJuego::on_fin_de_turno(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_fin_de_turno();
}


void PantallaJuego::on_reagrupar(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_reagrupar();
}


void PantallaJuego::on_reforzar(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_reforzar();
}


gint PantallaJuego::on_temporizador(gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_temporizador();
	return TRUE;
}


void PantallaJuego::on_destruir_ventana(GtkWidget* widget, gpointer data){
	gtk_widget_destroy(widget);
}


void PantallaJuego::on_mostrar_objetivo(GtkWidget* widget, gpointer data){
	PantallaJuego* instancia = (PantallaJuego*)data;
	instancia->get_controlador().manejar_evento_mostrar_objetivo();
}
