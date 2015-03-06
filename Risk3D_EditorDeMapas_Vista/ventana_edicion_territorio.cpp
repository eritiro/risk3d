#include "ventana_edicion_territorio.h"


VentanaEdicionTerritorio::VentanaEdicionTerritorio(ContextoEditor* contexto): VistaEdicionTerritorio(contexto){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Editar territorio...");
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE); 
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), NULL);


	/* Creo etiquetas y entradas. */
	this->etiqueta_seleccione_continente = gtk_label_new("Continente al que pertenece: ");
	this->etiqueta_nombre_territorio = gtk_label_new("Nombre:");
	this->etiqueta_coordenadas = gtk_label_new("Coordenadas:");
	
	this->etiqueta_x = gtk_label_new("X:");
	gtk_label_set_justify(GTK_LABEL(this->etiqueta_x), GTK_JUSTIFY_CENTER); 
	
	this->etiqueta_y = gtk_label_new("Y:");
	gtk_label_set_justify(GTK_LABEL(this->etiqueta_y), GTK_JUSTIFY_CENTER);
	
	this->entrada_nombre_territorio = gtk_entry_new();
	
	this->entrada_x = gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(this->entrada_x), 4);
	gtk_entry_set_editable(GTK_ENTRY(this->entrada_x), FALSE);
	
	this->entrada_y = gtk_entry_new();
	gtk_entry_set_width_chars(GTK_ENTRY(this->entrada_y), 4);
	gtk_entry_set_editable(GTK_ENTRY(this->entrada_y), FALSE);

	/* Creo botones. */
	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);

	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);

	/* Creo menu desplegable e inicializo lista de items del menu desplegable. */
	this->menu_desplegable = gtk_combo_new();
	this->lista_items_menu_desplegable = NULL;

	

	/* Creo tablas. */
	this->tabla_ventana = gtk_table_new(9, 7, TRUE);
	this->tabla_botones = gtk_table_new(1, 4, TRUE);
	
	gtk_table_attach(GTK_TABLE(this->tabla_botones), this->boton_aceptar, 1, 2, 0, 1, GTK_SHRINK, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_botones), this->boton_cancelar, 2, 3, 0, 1, GTK_SHRINK, GTK_SHRINK, 0, 0);
	
	/* Organizo widgets en tablas... */
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->etiqueta_seleccione_continente, 1, 6, 1, 2, GTK_SHRINK, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->menu_desplegable, 1, 6, 2, 3, GTK_SHRINK, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->etiqueta_nombre_territorio, 1, 6, 3, 4, GTK_SHRINK, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->entrada_nombre_territorio, 1, 6, 4, 5, GTK_SHRINK, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->etiqueta_coordenadas, 1, 6, 5, 6, GTK_SHRINK, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->etiqueta_x, 1, 2, 6, 7, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->entrada_x, 2, 3, 6, 7, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->etiqueta_y, 3, 4, 6, 7, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->entrada_y, 4, 5, 6, 7, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla_ventana), this->tabla_botones, 1, 6, 8, 9, GTK_SHRINK, GTK_SHRINK, 0, 0);

	
	get_controlador().inicializar();

	gtk_combo_set_popdown_strings (GTK_COMBO(this->menu_desplegable), this->lista_items_menu_desplegable);


	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->tabla_ventana, TRUE, TRUE, 0); 
	
	
	gtk_widget_show(this->boton_aceptar);
	gtk_widget_show(this->boton_cancelar);
	gtk_widget_show(this->tabla_botones);
	gtk_widget_show(this->etiqueta_x);
	gtk_widget_show(this->entrada_x);
	gtk_widget_show(this->etiqueta_y);
	gtk_widget_show(this->entrada_y);
	gtk_widget_show(this->etiqueta_coordenadas);
	gtk_widget_show(this->entrada_nombre_territorio);
	gtk_widget_show(this->etiqueta_nombre_territorio);
	gtk_widget_show(this->menu_desplegable);
	gtk_widget_show(this->etiqueta_seleccione_continente);
	gtk_widget_show(this->tabla_ventana);
	gtk_widget_show(this->ventana);
	
	get_controlador().inicializar();

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaEdicionTerritorio::~VentanaEdicionTerritorio(){}


void VentanaEdicionTerritorio::cerrar(){
	gtk_widget_destroy(GTK_WIDGET(this->ventana));
}


void VentanaEdicionTerritorio::set_coordenadas(int x, int y){
	gtk_entry_set_text(GTK_ENTRY(this->entrada_x), UtilidadesString::int_a_string(x).c_str());
	gtk_entry_set_text(GTK_ENTRY(this->entrada_y), UtilidadesString::int_a_string(y).c_str());
}


void VentanaEdicionTerritorio::set_continentes(ContenedorContinentes* continentes){
	for(IteradorContinentes i = continentes->begin(); i != continentes->end(); i++){
		char* nombre_continente = (char*)(*i)->get_nombre().c_str();
		this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, nombre_continente);
		gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry), FALSE);
	}
}


void VentanaEdicionTerritorio::set_continentes(ContenedorContinentes* continentes, Continente* continente){
	char* nombre_continente = (char*)continente->get_nombre().c_str();
	this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, nombre_continente);
	gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry), FALSE);
	
	for(IteradorContinentes i = continentes->begin(); i != continentes->end(); i++){
		if ((*i)->get_nombre() != nombre_continente){
			char* nombre_continente = (char*)(*i)->get_nombre().c_str();
			this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, nombre_continente);
			gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry), FALSE);
		}
	}
}


int VentanaEdicionTerritorio::get_coordenada_x(){
	const gchar* coord_x = gtk_entry_get_text(GTK_ENTRY(this->entrada_x));
	string string_coord_x = string(coord_x);
	return (UtilidadesString::string_a_int(string_coord_x));
}


int VentanaEdicionTerritorio::get_coordenada_y(){
	const gchar* coord_y = gtk_entry_get_text(GTK_ENTRY(this->entrada_y));
	string string_coord_y = string(coord_y);
	return (UtilidadesString::string_a_int(string_coord_y));
}


string VentanaEdicionTerritorio::get_nombnre_continente(){
	const gchar* continente_seleccionado = gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry));
	string string_continente_seleccionado = string(continente_seleccionado);
	return string_continente_seleccionado;
}


string VentanaEdicionTerritorio::get_nombre_territorio(){
	const gchar* nombre_territorio = gtk_entry_get_text(GTK_ENTRY(this->entrada_nombre_territorio));
	string string_nombre_territorio = string(nombre_territorio);
	return string_nombre_territorio;
}


void VentanaEdicionTerritorio::set_nombre_territorio(string nombre_territorio){
	char* nombre = (char*)nombre_territorio.c_str();
	gtk_entry_set_text(GTK_ENTRY(this->entrada_nombre_territorio), nombre);
	if (this->get_contexto()->get_es_territorio_nuevo())
		gtk_entry_set_editable(GTK_ENTRY(this->entrada_nombre_territorio), FALSE);
}



/* Definicion de callbacks. */

void VentanaEdicionTerritorio::on_destruir_ventana(GtkWidget* widget, gpointer data){
	VentanaEdicionTerritorio* instancia = (VentanaEdicionTerritorio*)data;
	gtk_widget_destroy(widget);
}


void VentanaEdicionTerritorio::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaEdicionTerritorio* instancia = (VentanaEdicionTerritorio*)data;
	instancia->get_controlador().manejar_evento_confirmar();
}


void VentanaEdicionTerritorio::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaEdicionTerritorio* instancia = (VentanaEdicionTerritorio*)data;
	gtk_widget_destroy(GTK_WIDGET(instancia->ventana));
}


void VentanaEdicionTerritorio::mostrar_alerta(string mensaje){
	Error err(mensaje);
}
