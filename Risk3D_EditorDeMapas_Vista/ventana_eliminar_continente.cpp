#include "ventana_eliminar_continente.h"


VentanaEliminarContinente::VentanaEliminarContinente(ContextoEditor* contexto) : VistaEliminarContinente(contexto){

	//pair<VentanaEliminarContinente*, string> parejita(this, "hola");

	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Eliminar continente...");
	gtk_window_resize(GTK_WINDOW(this->ventana), 300, 400);
	gtk_window_set_resizable(GTK_WINDOW(this->ventana), FALSE);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE); 
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), NULL);
	

	/*  Creo vbox y hbox. */
	this->vbox = gtk_vbox_new(FALSE, 0);
	this->vbox_area_ventana_desplazamiento = gtk_vbox_new(FALSE, 0);
	this->tabla = gtk_table_new(1, 6, TRUE);


	/* Creo botones aceptar y cancelar. */
	this->boton_aceptar = gtk_button_new_with_label("Aceptar");
	gtk_signal_connect(GTK_OBJECT(this->boton_aceptar), "clicked", GTK_SIGNAL_FUNC(on_aceptar), this);
	this->boton_cancelar = gtk_button_new_with_label("Cancelar");
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);

	/* Agrego a la vbox el widget etiqueta_seleccione_continente. */ 
	this->etiqueta_seleccione_continente = gtk_label_new("Seleccione continentes a eliminar:");
	gtk_box_pack_start(GTK_BOX(this->vbox), this->etiqueta_seleccione_continente, FALSE, FALSE, 5); 
	
	/* Agrego ventana o area con barras de desplazamiento a la ventana. */
	this->area_ventana_desplazamiento = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_usize(this->area_ventana_desplazamiento, 300, 200);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(this->area_ventana_desplazamiento),GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
	gtk_box_pack_start(GTK_BOX(this->vbox), this->area_ventana_desplazamiento, FALSE, FALSE, 2); 
	
		
	get_controlador().inicializar();

	gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(this->area_ventana_desplazamiento), this->vbox_area_ventana_desplazamiento);
	

	/* Organizo widgets. */
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_aceptar, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(this->tabla), this->boton_cancelar, 3, 4, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->vbox, FALSE, FALSE, 0); 
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->tabla, FALSE, FALSE, 0); 

	/* Muestro widgets. */
	gtk_widget_show(this->etiqueta_seleccione_continente);
	gtk_widget_show(this->area_ventana_desplazamiento);
	gtk_widget_show_all(this->vbox_area_ventana_desplazamiento);
	gtk_widget_show(this->boton_aceptar);
	gtk_widget_show(this->boton_cancelar);
	gtk_widget_show(this->tabla);
	gtk_widget_show(this->vbox);
	gtk_widget_show(this->ventana);
	
	
	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaEliminarContinente::~VentanaEliminarContinente(){
	foreach(IteradorPares, i, this->contenedor_pares){
		delete(*i);
	}
}


void VentanaEliminarContinente::cerrar(){
	gtk_widget_destroy(GTK_WIDGET(this->ventana));
}


void VentanaEliminarContinente::set_continentes(ContenedorContinentes* continentes){
	for(IteradorContinentes i = continentes->begin(); i != continentes->end(); i++){
		char* nombre_continente = (char*)(*i)->get_nombre().c_str();
		Par* par = new Par(this, string(nombre_continente));
		this->contenedor_pares.push_back(par);

		this->boton_check = gtk_check_button_new_with_label(nombre_continente);
		gtk_signal_connect(GTK_OBJECT(this->boton_check), "toggled", GTK_SIGNAL_FUNC(on_seleccionado), par);
		gtk_box_pack_start(GTK_BOX(this->vbox_area_ventana_desplazamiento), this->boton_check, FALSE, FALSE, 0);
	}
}


/* Definicion de callbacks. */

void VentanaEliminarContinente::on_aceptar(GtkWidget* widget, gpointer data){
	VentanaEliminarContinente* instancia = (VentanaEliminarContinente*)data;
	instancia->get_controlador().manejar_evento_confirmar();
}


void VentanaEliminarContinente::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaEliminarContinente* instancia = (VentanaEliminarContinente*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}


void VentanaEliminarContinente::on_destruir_ventana(GtkWidget* widget, gpointer data){
	VentanaEliminarContinente* instancia = (VentanaEliminarContinente*)data;
	gtk_widget_destroy(widget);
}


void VentanaEliminarContinente::on_seleccionado(GtkWidget* widget, gpointer data){
	Par* par = (Par*)data;
	if (GTK_TOGGLE_BUTTON(widget)->active){
		par->first->get_controlador().manejar_evento_seleccionado(par->second);
	}
	else
		par->first->get_controlador().manejar_evento_desseleccionado(par->second);
}