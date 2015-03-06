#include "ventana_modificar_continente.h"


VentanaModificarContinente::VentanaModificarContinente(ContextoEditor* contexto) : VistaModificarContinente(contexto){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Modificar continente...");
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE); 
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), NULL);


	/* Creo entradas de texto, etiquetas, menu desplegable, lista items y botones... */
	this->entrada_nuevo_nombre = gtk_entry_new();
	this->entrada_nuevo_bonus = gtk_entry_new();
	
	this->etiqueta_seleccione_continente = gtk_label_new("Seleccion un continente: ");
	this->etiqueta_nuevo_nombre = gtk_label_new("Nuevo nombre: ");
	this->etiqueta_nuevo_bonus = gtk_label_new("Nuevo bonus: ");

	
	this->boton_cargar_informacion_continente = gtk_button_new_with_label("Cargar Informacion");
	gtk_signal_connect(GTK_OBJECT(this->boton_cargar_informacion_continente), "clicked", GTK_SIGNAL_FUNC(on_cargar_informacion_continente), this);

	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	gtk_widget_set_sensitive(this->boton_aceptar, FALSE);
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);

	this->lista_items_menu_desplegable = NULL;
	
	this->menu_desplegable = gtk_combo_new();
	
	
	/* Creo tabla y organizo widgets... */
	this->tabla = gtk_table_new(11, 4, TRUE);
	
	gtk_table_attach(GTK_TABLE(this->tabla), this->etiqueta_seleccione_continente, 1, 3, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->menu_desplegable, 1, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_cargar_informacion_continente, 1, 3, 3, 4, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->etiqueta_nuevo_nombre, 1, 3, 4, 5, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->entrada_nuevo_nombre, 1, 3, 5, 6, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->etiqueta_nuevo_bonus, 1, 3, 6, 7, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->entrada_nuevo_bonus, 1, 3, 7, 8, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_aceptar, 1, 2, 9, 10, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_cancelar, 2, 3, 9, 10, GTK_FILL, GTK_FILL, 0, 0);


	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->tabla, TRUE, TRUE, 0); 

	get_controlador().inicializar();

	gtk_combo_set_popdown_strings (GTK_COMBO(this->menu_desplegable), this->lista_items_menu_desplegable);

	gtk_widget_show(this->tabla);
	gtk_widget_show(this->etiqueta_nuevo_nombre);
	gtk_widget_show(this->etiqueta_nuevo_bonus);
	gtk_widget_show(this->entrada_nuevo_nombre);
	gtk_widget_show(this->entrada_nuevo_bonus);
	gtk_widget_show(this->menu_desplegable);
	gtk_widget_show(this->etiqueta_seleccione_continente);
	gtk_widget_show(this->boton_aceptar);
	gtk_widget_show(this->boton_cancelar);
	gtk_widget_show(this->boton_cargar_informacion_continente);
	gtk_widget_show(this->ventana);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaModificarContinente::~VentanaModificarContinente(){}


void VentanaModificarContinente::set_continentes(ContenedorContinentes* continentes){
	for(IteradorContinentes i = continentes->begin(); i != continentes->end(); i++){
		char* nombre_continente = (char*)(*i)->get_nombre().c_str();
		this->lista_items_menu_desplegable = g_list_append(this->lista_items_menu_desplegable, nombre_continente);
		gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry), FALSE);
	}
}


string VentanaModificarContinente::get_nombre_continente_seleccionado(){
	const gchar* nombre_continente_seleccionado = gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(this->menu_desplegable)->entry));
	return nombre_continente_seleccionado;
}


void VentanaModificarContinente::set_continente_seleccionado(ContenedorContinentes* continentes, string nombre_continente_seleccionado){
	int bonus_continente_seleccionado = 0;
	for (IteradorContinentes i = continentes->begin(); i != continentes->end(); i++){
		char* nombre_continente = (char*)(*i)->get_nombre().c_str();
		string string_nombre_continente = string(nombre_continente);
		if (string_nombre_continente == nombre_continente_seleccionado){
			bonus_continente_seleccionado = (int)(*i)->get_bonus();
			break;
		}
	}
	gtk_entry_set_text(GTK_ENTRY(this->entrada_nuevo_nombre), nombre_continente_seleccionado.c_str());
	gtk_entry_set_text(GTK_ENTRY(this->entrada_nuevo_bonus), (UtilidadesString::int_a_string(bonus_continente_seleccionado)).c_str());
}


void VentanaModificarContinente::cerrar(){
	gtk_widget_destroy(GTK_WIDGET(this->ventana));
}


string VentanaModificarContinente::get_nuevo_nombre_continente(){
	const gchar* nuevo_nombre_continente = gtk_entry_get_text(GTK_ENTRY(this->entrada_nuevo_nombre));
	string nuevo_nombre = string(nuevo_nombre_continente);
	return nuevo_nombre;
}


string VentanaModificarContinente::get_nuevo_bonus_continente(){
	const gchar* nuevo_bonus_continente = gtk_entry_get_text(GTK_ENTRY(this->entrada_nuevo_bonus));
	return string(nuevo_bonus_continente);
}



/* Definicion de callbacks. */

void VentanaModificarContinente::on_cargar_informacion_continente(GtkWidget* widget, gpointer data){
	VentanaModificarContinente* instancia = (VentanaModificarContinente*)data;	
	instancia->get_controlador().manejar_evento_cargar_informacion_continente();
	gtk_widget_set_sensitive(instancia->boton_aceptar, TRUE);
	gtk_widget_set_sensitive(instancia->menu_desplegable, FALSE);
}


void VentanaModificarContinente::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaModificarContinente* instancia = (VentanaModificarContinente*)data;
	instancia->get_controlador().manejar_evento_confirmar();
}


void VentanaModificarContinente::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaModificarContinente* instancia = (VentanaModificarContinente*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}


void VentanaModificarContinente::on_destruir_ventana(GtkWidget* widget, gpointer data){
	VentanaModificarContinente* instancia = (VentanaModificarContinente*)data;
	gtk_widget_destroy(widget);
}

void VentanaModificarContinente::mostrar_alerta(string mensaje){
	Error err(mensaje);
}
