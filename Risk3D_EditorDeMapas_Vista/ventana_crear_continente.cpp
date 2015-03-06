#include "ventana_crear_continente.h"

VentanaCrearContinente::VentanaCrearContinente(ContextoEditor* contexto) : VistaCrearContinente(contexto) {
	/* Creo ventana... */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Crear continente...");
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE); 
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), NULL);



	/* Creo entradas de texto, etiquetas y botones... */
	this->entrada_continente = gtk_entry_new();
	this->entrada_bonus = gtk_entry_new();

	this->etiqueta_nombre = gtk_label_new("Nombre: ");
	this->etiqueta_bonus = gtk_label_new("Bonus: ");

	
	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);


	/* Creo tabla y organizo widgets... */
	this->tabla = gtk_table_new(6, 6, TRUE);
	
	gtk_table_attach(GTK_TABLE(this->tabla), this->etiqueta_nombre, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->etiqueta_bonus, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->entrada_continente, 2, 5, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->entrada_bonus, 2, 5, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_aceptar, 2, 3, 5, 6, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_cancelar, 3, 4, 5, 6, GTK_FILL, GTK_FILL, 0, 0);


	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->tabla, TRUE, TRUE, 0); 

	gtk_widget_show(this->tabla);
	gtk_widget_show(this->etiqueta_nombre);
	gtk_widget_show(this->etiqueta_bonus);
	gtk_widget_show(this->entrada_continente);
	gtk_widget_show(this->entrada_bonus);
	gtk_widget_show(this->boton_aceptar);
	gtk_widget_show(this->boton_cancelar);
	gtk_widget_show(this->ventana);

	get_controlador().inicializar();

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaCrearContinente::~VentanaCrearContinente(){}


string VentanaCrearContinente::get_nombre_continente(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_continente));
}


string VentanaCrearContinente::get_bonus_continente(){
	return gtk_entry_get_text(GTK_ENTRY(this->entrada_bonus));
}


void VentanaCrearContinente::cerrar(){
	gtk_widget_destroy(GTK_WIDGET(this->ventana));
}


/* Definicion de callbacks. */

void VentanaCrearContinente::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaCrearContinente* instancia = (VentanaCrearContinente*)data;
	instancia->get_controlador().manejar_evento_confirmar();
}


void VentanaCrearContinente::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaCrearContinente* instancia = (VentanaCrearContinente*)data;
	gtk_widget_destroy(GTK_WIDGET(instancia->ventana));
}


void VentanaCrearContinente::on_destruir_ventana(GtkWidget* widget, gpointer data){
	VentanaCrearContinente* instancia = (VentanaCrearContinente*)data;
	gtk_widget_destroy(widget);
}

void VentanaCrearContinente::mostrar_alerta(string mensaje){
	Error err(mensaje);
}
