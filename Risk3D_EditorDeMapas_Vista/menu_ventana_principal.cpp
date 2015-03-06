#include "menu_ventana_principal.h"


/* Definicion metodos de clase. */

MenuVentanaPrincipal::MenuVentanaPrincipal(ControladorEditorDeMapa* controlador) : controlador(controlador){
	/* Creo barra de menu. */
	this->barra_menu = gtk_menu_bar_new();
	this->crear_menu_editor();
	this->crear_menu_continente();
	this->crear_menu_territorio();
	this->crear_menu_objetivos();
	this->crear_menu_ayuda();
}

void MenuVentanaPrincipal::crear_menu_editor(){
	/* Creo menu "Editor" y submenu: "Nuevo mapa", "Abrir mapa", "Guardar mapa", 
	"Guardar mapa como..." y "Salir". */
	this->menu_editor = gtk_menu_item_new_with_label("Editor");
	gtk_menu_bar_append(GTK_MENU_BAR(this->barra_menu), this->menu_editor);
	
	this->submenu_editor = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->menu_editor), this->submenu_editor);
	
	
	this->item_editor_nuevo_mapa = gtk_menu_item_new_with_label("Nuevo mapa");
	gtk_menu_append(GTK_MENU(this->submenu_editor), this->item_editor_nuevo_mapa);
	gtk_signal_connect(GTK_OBJECT(this->item_editor_nuevo_mapa), "activate", GTK_SIGNAL_FUNC(on_nuevo_mapa), this);


	this->item_editor_abrir_mapa = gtk_menu_item_new_with_label("Abrir mapa...");
	gtk_menu_append(GTK_MENU(this->submenu_editor), this->item_editor_abrir_mapa);
	gtk_signal_connect(GTK_OBJECT(this->item_editor_abrir_mapa), "activate", GTK_SIGNAL_FUNC(on_abrir_mapa), this);

	this->item_editor_cerrar_mapa = gtk_menu_item_new_with_label("Cerrar mapa");
	gtk_menu_append(GTK_MENU(this->submenu_editor), this->item_editor_cerrar_mapa);
	gtk_signal_connect(GTK_OBJECT(this->item_editor_cerrar_mapa), "activate", GTK_SIGNAL_FUNC(on_cerrar_mapa), this);

	this->item_editor_guardar_mapa = gtk_menu_item_new_with_label("Guardar mapa");
	gtk_menu_append(GTK_MENU(this->submenu_editor), this->item_editor_guardar_mapa);
	gtk_signal_connect(GTK_OBJECT(this->item_editor_guardar_mapa), "activate", GTK_SIGNAL_FUNC(on_guardar_mapa), this);
	
	this->item_editor_guardar_como_mapa = gtk_menu_item_new_with_label("Guardar mapa como...");
	gtk_menu_append(GTK_MENU(this->submenu_editor), this->item_editor_guardar_como_mapa);
	gtk_signal_connect(GTK_OBJECT(this->item_editor_guardar_como_mapa), "activate", GTK_SIGNAL_FUNC(on_guardar_como_mapa), this);

	this->item_editor_salir = gtk_menu_item_new_with_label("Salir");
	gtk_menu_append(GTK_MENU(this->submenu_editor), this->item_editor_salir);
	gtk_signal_connect(GTK_OBJECT(this->item_editor_salir), "activate", GTK_SIGNAL_FUNC(on_editor_salir), this);
}


void MenuVentanaPrincipal::crear_menu_continente(){
	
	/* Creo menu "Continente" y submenu: "Crear continente", "Modificar continente",
	 * "Eliminar continente".*/
	this->menu_continente = gtk_menu_item_new_with_label("Continente");
	gtk_menu_bar_append(GTK_MENU_BAR(this->barra_menu), this->menu_continente);
	
	this->submenu_continente = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->menu_continente), this->submenu_continente);


	this->item_continente_crear = gtk_menu_item_new_with_label("Crear continente");
	gtk_menu_append(GTK_MENU(this->submenu_continente), this->item_continente_crear);
	gtk_signal_connect(GTK_OBJECT(this->item_continente_crear), "activate", GTK_SIGNAL_FUNC(on_crear_continente), this);

	this->item_continente_modificar = gtk_menu_item_new_with_label("Modificar continente");
	gtk_menu_append(GTK_MENU(this->submenu_continente), this->item_continente_modificar);
	gtk_signal_connect(GTK_OBJECT(this->item_continente_modificar), "activate", GTK_SIGNAL_FUNC(on_modificar_continente), this);

	this->item_continente_eliminar = gtk_menu_item_new_with_label("Eliminar continente");
	gtk_menu_append(GTK_MENU(this->submenu_continente), this->item_continente_eliminar);
	gtk_signal_connect(GTK_OBJECT(this->item_continente_eliminar), "activate", GTK_SIGNAL_FUNC(on_eliminar_continente), this);
}


void MenuVentanaPrincipal::crear_menu_territorio(){
	/* Creo menu "Territorio" y submenu: "Editar territorio", "Adayacencias" y "Eliminar territorio".*/
	this->menu_territorio = gtk_menu_item_new_with_label("Territorio");
	gtk_menu_bar_append(GTK_MENU_BAR(this->barra_menu), this->menu_territorio);
	
	this->submenu_territorio = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->menu_territorio), this->submenu_territorio);


	this->item_territorio_editar = gtk_menu_item_new_with_label("Editar territorio");
	gtk_menu_append(GTK_MENU(this->submenu_territorio), this->item_territorio_editar);
	gtk_signal_connect(GTK_OBJECT(this->item_territorio_editar), "activate", GTK_SIGNAL_FUNC(on_editar_territorio), this);

	this->item_territorio_adyacencias = gtk_menu_item_new_with_label("Editar adyacencias");
	gtk_menu_append(GTK_MENU(this->submenu_territorio), this->item_territorio_adyacencias);
	gtk_signal_connect(GTK_OBJECT(this->item_territorio_adyacencias), "activate", GTK_SIGNAL_FUNC(on_editar_adyacencias), this);
	

	this->item_territorio_eliminar = gtk_menu_item_new_with_label("Eliminar territorio");
	gtk_menu_append(GTK_MENU(this->submenu_territorio), this->item_territorio_eliminar);
	gtk_signal_connect(GTK_OBJECT(this->item_territorio_eliminar), "activate", GTK_SIGNAL_FUNC(on_eliminar_territorio), this);

}


void MenuVentanaPrincipal::crear_menu_ayuda(){
	/* Creo menu "Ayuda" y submenu: "Ayuda Web" y "Acerca de...".*/
	this->menu_ayuda = gtk_menu_item_new_with_label("Ayuda");
	gtk_menu_bar_append(GTK_MENU_BAR(this->barra_menu), this->menu_ayuda);
	
	this->submenu_ayuda = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->menu_ayuda), this->submenu_ayuda);


	this->item_ayuda_web = gtk_menu_item_new_with_label("Ayuda Web");
	gtk_menu_append(GTK_MENU(this->submenu_ayuda), this->item_ayuda_web);

	this->item_ayuda_acercade = gtk_menu_item_new_with_label("Acerca de...");
	gtk_menu_append(GTK_MENU(this->submenu_ayuda), this->item_ayuda_acercade);
	gtk_signal_connect(GTK_OBJECT(this->item_ayuda_acercade), "activate", GTK_SIGNAL_FUNC(on_acerca_de), this);

}


void MenuVentanaPrincipal::crear_menu_objetivos(){
	this->menu_objetivos = gtk_menu_item_new_with_label("Objetivos");
	gtk_menu_bar_append(GTK_MENU_BAR(this->barra_menu), this->menu_objetivos);

	this->submenu_objetivos = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->menu_objetivos), this->submenu_objetivos);

	this->item_administrar_objetivos = gtk_menu_item_new_with_label("Objetivos");
	gtk_menu_append(GTK_MENU(this->submenu_objetivos), this->item_administrar_objetivos);
	gtk_signal_connect(GTK_OBJECT(this->item_administrar_objetivos), "activate", GTK_SIGNAL_FUNC(on_objetivos), this);
}


void MenuVentanaPrincipal::mostrar_menu_editor(){
	/* Muestro menu y submenu "Editor".*/
	gtk_widget_show(this->item_editor_nuevo_mapa);
	gtk_widget_show(this->item_editor_abrir_mapa);
	gtk_widget_show(this->item_editor_guardar_mapa);
	gtk_widget_show(this->item_editor_guardar_como_mapa);
	gtk_widget_show(this->item_editor_cerrar_mapa);
	gtk_widget_show(this->item_editor_salir);
	gtk_widget_show(this->menu_editor);
}


void MenuVentanaPrincipal::mostrar_menu_continente(){
	/* Muestro menu y submenu "Continente".*/
	gtk_widget_show(this->item_continente_crear);
	gtk_widget_show(this->item_continente_modificar);
	gtk_widget_show(this->item_continente_eliminar);
	gtk_widget_show(this->menu_continente);
}


void MenuVentanaPrincipal::mostrar_menu_territorio(){
	/* Muestro menu y submenu "Territorio".*/
	gtk_widget_show(this->item_territorio_editar);
	gtk_widget_show(this->item_territorio_eliminar);
	gtk_widget_show(this->item_territorio_adyacencias);
	gtk_widget_show(this->menu_territorio);
}


void MenuVentanaPrincipal::mostrar_menu_ayuda(){
	/* Muestro menu y submenu "Ayuda" y "Acerca de...".*/
	gtk_widget_show(this->item_ayuda_web);
	gtk_widget_show(this->item_ayuda_acercade);
	gtk_widget_show(this->menu_ayuda);
}


void MenuVentanaPrincipal::mostrar_menu_objetivos(){
	gtk_widget_show(this->item_administrar_objetivos);
	gtk_widget_show(this->menu_objetivos);
}


void MenuVentanaPrincipal::mostrar_barra_menu(){
	/* Muetsro barra de menu. */
	this->mostrar_menu_editor();
	this->mostrar_menu_continente();
	this->mostrar_menu_territorio();
	this->mostrar_menu_objetivos();
	this->mostrar_menu_ayuda();
	gtk_widget_show(this->barra_menu);
}


GtkWidget* MenuVentanaPrincipal::get_widget(){
	return (this->barra_menu);
}


MenuVentanaPrincipal::~MenuVentanaPrincipal(){
}


/* Definicion de callbacks. */

void MenuVentanaPrincipal::on_nuevo_mapa(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_nuevo_mapa();
}


void MenuVentanaPrincipal::on_abrir_mapa(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_abrir_mapa();
}


void MenuVentanaPrincipal::on_cerrar_mapa(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_cerrar_mapa();
}


void MenuVentanaPrincipal::on_guardar_mapa(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_guardar_mapa();
}


void MenuVentanaPrincipal::on_guardar_como_mapa(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_guardar_como_mapa();
}


void MenuVentanaPrincipal::on_editor_salir(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_salir_editor();
}


void MenuVentanaPrincipal::on_crear_continente(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_crear_continente();
}


void MenuVentanaPrincipal::on_modificar_continente(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_modificar_continente();
}


void MenuVentanaPrincipal::on_eliminar_continente(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_eliminar_continente();
}


void MenuVentanaPrincipal::on_editar_territorio(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_modo_editar_territorio();
}


void MenuVentanaPrincipal::on_editar_adyacencias(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_modo_editar_adyacencias();
}


void MenuVentanaPrincipal::on_eliminar_territorio(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_modo_eliminar_territorio();
}


void MenuVentanaPrincipal::on_objetivos(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_administrar_objetivos();
}


void MenuVentanaPrincipal::on_acerca_de(GtkWidget* widget, gpointer data){
	MenuVentanaPrincipal* instancia = (MenuVentanaPrincipal*)data;
	instancia->controlador->manejar_evento_mostrar_acerca_de();
}