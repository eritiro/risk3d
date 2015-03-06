#include "area_de_edicion.h"

AreaDeEdicion::AreaDeEdicion(ControladorEditorDeMapa* controlador) : controlador_editor_de_mapa(controlador){
	this->textura = new Textura();
	

	/* Creo ventana de desplazamiento automatica... */
	this->ventana_desplazamiento = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_usize(this->ventana_desplazamiento, 900, 530);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(this->ventana_desplazamiento),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	
	

	/* Muestro widgets... */
	gtk_widget_show(this->ventana_desplazamiento);
}


void AreaDeEdicion::set_textura(string ruta_textura){


	int ancho_original = 0;
	int alto_original = 0;
	gdk_pixbuf_get_file_info (ruta_textura.c_str(), &ancho_original, &alto_original);
	if(ancho_original == 0)
		throw ExcepcionDeNegocio("No se puede leer la textura del mapa.");

	this->textura->set_ruta(ruta_textura);
	this->layout = gtk_layout_new(NULL, NULL);
	this->event_box = gtk_event_box_new();
	gtk_container_add(GTK_CONTAINER(this->ventana_desplazamiento), this->layout);
	if (this->textura->cargar()){
		gtk_layout_set_size(GTK_LAYOUT(this->layout), this->textura->get_ancho(), this->textura->get_alto());
		gtk_container_add(GTK_CONTAINER(this->event_box), this->textura->get_ptr_widget_imagen());
		gtk_container_add(GTK_CONTAINER(this->layout), this->event_box);

		/* Muestro widgets... */
		gtk_widget_show(this->textura->get_ptr_widget_imagen());
		gtk_widget_show(this->event_box);
		gtk_widget_show(this->layout);

	}
	g_signal_connect(G_OBJECT(this->event_box), "button_press_event", G_CALLBACK(on_evento_clicked), this);
}


AreaDeEdicion::~AreaDeEdicion(){
	this->destruir_iconos();
	delete(this->textura);
}


void AreaDeEdicion::ocultar_textura(){
	this->destruir_iconos();
	gtk_widget_destroy(this->textura->get_ptr_widget_imagen());
	gtk_widget_destroy(this->event_box);
	gtk_widget_destroy(this->layout);
}


GtkWidget* AreaDeEdicion::get_widget(){
	return this->ventana_desplazamiento;
}

void AreaDeEdicion::refrescar_mapa(Mapa* mapa){
	this->destruir_iconos();
	foreach(IteradorTerritorios, i, mapa->get_territorios()){
		IconoTerritorio*  icono = new IconoTerritorioComun(*i, this->controlador_editor_de_mapa);
		gtk_layout_put(GTK_LAYOUT(this->layout), icono->get_widget(), (*i)->get_posicion().get_x() - (ANCHO_ICONO / 2),(*i)->get_posicion().get_y() - (ALTO_ICONO / 2));
		this->iconos.push_back(icono);
	}
}


void AreaDeEdicion::refrescar_mapa(Mapa* mapa, Territorio* territorio_seleccionado){
	this->destruir_iconos();
	foreach(IteradorTerritorios, i, mapa->get_territorios()){
		IconoTerritorio*  icono;
		if(territorio_seleccionado == *i)
			icono = new IconoTerritorioActivo(*i, this->controlador_editor_de_mapa);
		else if(territorio_seleccionado->es_adyacente_a(*i))
			icono = new IconoTerritorioAdyacente(*i, this->controlador_editor_de_mapa);
		else
			icono = new IconoTerritorioComun(*i, this->controlador_editor_de_mapa);

		gtk_layout_put(GTK_LAYOUT(this->layout), icono->get_widget(), (*i)->get_posicion().get_x() - (ANCHO_ICONO / 2),(*i)->get_posicion().get_y() - (ALTO_ICONO / 2));
		this->iconos.push_back(icono);
	}
}


void AreaDeEdicion::destruir_iconos(){
	foreach(IteradorIconos, i, this->iconos){
		delete *i;
	}
	iconos = ContenedorIconos();
}



/* Definicion de callbacks. */

void AreaDeEdicion::on_evento_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data){
	AreaDeEdicion* instancia = (AreaDeEdicion*)data;
	instancia->controlador_editor_de_mapa->manejar_evento_edicion(evento->x, evento->y);
}
