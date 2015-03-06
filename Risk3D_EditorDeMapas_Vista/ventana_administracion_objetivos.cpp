#include "ventana_administracion_objetivos.h"


VentanaAdministracionObjetivos::VentanaAdministracionObjetivos(ContextoEditor* contexto) : VistaAdministrarObjetivos(contexto){
	/* Creo ventana. */
	this->ventana = gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(this->ventana), "Objetivos...");
	gtk_window_set_position(GTK_WINDOW(this->ventana), GTK_WIN_POS_CENTER);
	gtk_dialog_set_has_separator(GTK_DIALOG(this->ventana), FALSE);
	gtk_window_resize(GTK_WINDOW(this->ventana), 200, 20);

	/* Creo otros widgets. */
	this->boton_agregar_nuevo = gtk_button_new_with_label("Nuevo");
	this->boton_cancelar = gtk_button_new_with_label("Cerrar");

	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_agregar_nuevo), "clicked", GTK_SIGNAL_FUNC(on_agregar_nuevo), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);
		
	this->get_controlador().inicializar();

	/* Muestro widgets. */
	gtk_widget_show_all(this->ventana);

	gtk_dialog_run(GTK_DIALOG(this->ventana));
}


VentanaAdministracionObjetivos::~VentanaAdministracionObjetivos(){
	foreach(IteradorParesVentanaObjetivo, i, this->contenedor_pares){
		delete(*i);
	}
}


void VentanaAdministracionObjetivos::cerrar(){
	gtk_widget_destroy(this->ventana);
}


void VentanaAdministracionObjetivos::mostrar_mensaje_alerta(string mensaje){
	Error err(mensaje);
}


void VentanaAdministracionObjetivos::set_requisitos(ContenedorRequisitos contenedor_requisitos){
	this->hbox_botones = gtk_hbox_new(FALSE, 0);
	this->vbox_principal = gtk_vbox_new(FALSE, 0);
	

	foreach(IteradorRequisitos, i, contenedor_requisitos){
		ParVentanaObjetivo* par = new ParVentanaObjetivo(this, (*i));
		this->contenedor_pares.push_back(par);
		
		string nombre_requisito = "Objetivo " + UtilidadesString::int_a_string((*i)->get_id()) + ":";

		this->etiqueta_nombre_objetivo = gtk_label_new(nombre_requisito.c_str());
		this->boton_modificar = gtk_button_new_with_label("Modificar");
		this->boton_eliminar = gtk_button_new_with_label("Eliminar");
		this->hbox = gtk_hbox_new(FALSE, 0);
		
		gtk_box_pack_start(GTK_BOX(this->hbox), this->etiqueta_nombre_objetivo, FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_modificar, TRUE, TRUE, 5);
		gtk_box_pack_start(GTK_BOX(this->hbox), this->boton_eliminar, TRUE, TRUE, 1);
		gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->hbox, FALSE, FALSE, 1);
		
		gtk_signal_connect(GTK_OBJECT(this->boton_modificar), "clicked", GTK_SIGNAL_FUNC(on_modificar), par);
		gtk_signal_connect(GTK_OBJECT(this->boton_eliminar), "clicked", GTK_SIGNAL_FUNC(on_eliminar), par);
	}

	gtk_box_pack_start(GTK_BOX(this->hbox_botones), this->boton_agregar_nuevo, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(this->hbox_botones), this->boton_cancelar, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(this->vbox_principal), this->hbox_botones, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(this->ventana)->vbox), this->vbox_principal, FALSE, FALSE, 0);

}


void VentanaAdministracionObjetivos::abrir_ventana_edicion_objetivo(){
	VentanaEdicionObjetivo ventana_edicion_objetivo(get_contexto());
	this->get_controlador().manejar_evento_actualizar();
}


void VentanaAdministracionObjetivos::actualizar(ContenedorRequisitos contenedor_requisitos){
	gtk_widget_destroy(this->vbox_principal);
	
	/* Creo otros widgets. */
	this->boton_agregar_nuevo = gtk_button_new_with_label("Nuevo");
	this->boton_cancelar = gtk_button_new_with_label("Cerrar");

	/* Callbacks. */
	gtk_signal_connect(GTK_OBJECT(this->ventana), "delete_event", GTK_SIGNAL_FUNC(on_destruir_ventana), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_agregar_nuevo), "clicked", GTK_SIGNAL_FUNC(on_agregar_nuevo), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_cancelar), "clicked", GTK_SIGNAL_FUNC(on_cancelar), this);

	this->set_requisitos(contenedor_requisitos);

	gtk_window_resize(GTK_WINDOW(this->ventana), 200, 20);
	gtk_widget_show_all(this->ventana);
}


/* Definicion de callbacks. */

void VentanaAdministracionObjetivos::on_destruir_ventana(GtkWidget* widget, gpointer data){
	gtk_widget_destroy(widget);
}


void VentanaAdministracionObjetivos::on_agregar_nuevo(GtkWidget* widget, gpointer data){
	VentanaAdministracionObjetivos* instancia = (VentanaAdministracionObjetivos*)data;
	instancia->get_controlador().manejar_evento_agregar_nuevo();
}


void VentanaAdministracionObjetivos::on_cancelar(GtkWidget* widget, gpointer data){
	VentanaAdministracionObjetivos* instancia = (VentanaAdministracionObjetivos*)data;
	instancia->get_controlador().manejar_evento_cancelar();
}



void VentanaAdministracionObjetivos::on_modificar(GtkWidget* widget, gpointer data){
	ParVentanaObjetivo* par = (ParVentanaObjetivo*)data;
	VentanaAdministracionObjetivos* instancia = par->first;
	instancia->get_controlador().manejar_evento_modificar(par->second);
}


void VentanaAdministracionObjetivos::on_eliminar(GtkWidget* widget, gpointer data){
	ParVentanaObjetivo* par = (ParVentanaObjetivo*)data;
	VentanaAdministracionObjetivos* instancia = par->first;
	instancia->get_controlador().manejar_evento_eliminar(par->second);
}


