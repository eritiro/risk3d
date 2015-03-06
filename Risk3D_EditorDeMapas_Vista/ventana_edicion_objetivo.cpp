#include "ventana_edicion_objetivo.h"



VentanaEdicionObjetivo::VentanaEdicionObjetivo(ContextoEditor* contexto_editor) : VistaEditarObjetivo(contexto_editor){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_modal(GTK_WINDOW(this->ventana), TRUE);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Editar objetivo...");
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_resize(GTK_WINDOW(this->ventana), 200, 100);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);

	/* Creo otros widgets. */
	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");

	/* Creo boxes. */
	this->vbox_principal = gtk_vbox_new(FALSE, 0);
	this->hbox_botones = gtk_hbox_new(FALSE, 0);
	this->vbox_continentes = gtk_vbox_new(FALSE, 0);


	gtk_box_pack_start(GTK_BOX(this->hbox_botones), this->boton_aceptar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_botones), this->boton_cancelar, TRUE, TRUE, 0);

	
	gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->vbox_continentes, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->hbox_botones, FALSE, FALSE, 0);
	
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(this->ventana)->vbox), this->vbox_principal);


	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);
	

	this->get_controlador().inicializar();

	gtk_widget_show_all(this->ventana);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaEdicionObjetivo::~VentanaEdicionObjetivo(){
}


void VentanaEdicionObjetivo::cerrar(){
	gtk_widget_destroy(this->ventana);
}


void VentanaEdicionObjetivo::set_continentes_default(ContenedorContinentes* contenedor_continentes){
	foreach(IteradorContinentes, i, *contenedor_continentes){
		set_continente((*i), 0);
	}
}


void VentanaEdicionObjetivo::agregar_continente_valor(Continente* continente, int cantidad_territorios_seleccionado){	
	set_continente(continente, cantidad_territorios_seleccionado);
}


void VentanaEdicionObjetivo::set_continente(Continente* continente, int valor){
	ContenedorTerritorios* contenedor_territorios = &((continente)->get_territorios());
	int cantidad_territorios = contenedor_territorios->size();
	this->ajuste_rango_seleccion = gtk_adjustment_new(valor, 0, cantidad_territorios, 1, 1, 0);
	this->rango_seleccion = gtk_spin_button_new(GTK_ADJUSTMENT(this->ajuste_rango_seleccion), 0.0, 0);
	this->etiqueta_continente = gtk_label_new(continente->get_nombre().c_str());
	this->hbox = gtk_hbox_new(FALSE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox), this->etiqueta_continente, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox), this->rango_seleccion, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(this->vbox_continentes), this->hbox, FALSE, FALSE, 3);
	
	this->tabla_continente_valor[continente->get_id()] = this->rango_seleccion;
}


void VentanaEdicionObjetivo::mostrar_mensaje_alerta(string mensaje){
	Error err(mensaje);
}


int VentanaEdicionObjetivo::get_valor_por_continente(Continente* continente){
	return gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(this->tabla_continente_valor[continente->get_id()])); 
}


/* Definicion de callbacks. */

void VentanaEdicionObjetivo::on_destruir_ventana(GtkWidget* widget, gpointer data){
	gtk_widget_destroy(widget);
}


void VentanaEdicionObjetivo::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaEdicionObjetivo* instancia = (VentanaEdicionObjetivo*)data;
	instancia->get_controlador().manejar_evento_aceptar();
}


void VentanaEdicionObjetivo::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaEdicionObjetivo* instancia = (VentanaEdicionObjetivo*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}