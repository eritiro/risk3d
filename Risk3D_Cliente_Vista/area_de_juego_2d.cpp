#include "area_de_juego_2d.h"

AreaDeJuego2D::AreaDeJuego2D(ControladorPantallaJuego& controlador) 
	: controlador(controlador) {
	this->imagen_activa = false;
	this->layout = gtk_layout_new(NULL, NULL);
	gtk_layout_set_size(GTK_LAYOUT(this->layout), ANCHO_AREA_DE_JUEGO, ALTO_AREA_DE_JUEGO);
	gtk_widget_set_size_request(this->layout, ANCHO_AREA_DE_JUEGO, ALTO_AREA_DE_JUEGO);
	this->caja_de_eventos = gtk_event_box_new();
	g_signal_connect(G_OBJECT(this->caja_de_eventos), "button_press_event", G_CALLBACK(on_evento_clicked), this);
}


AreaDeJuego2D::~AreaDeJuego2D(){
}

GtkWidget* AreaDeJuego2D::get_widget(){
	return this->layout;
}


void AreaDeJuego2D::actualizar(InfoJuego* info){

	this->mostrar_imagen(info->get_mapa().get_ruta_textura());
	this->destruir_iconos();
	this->dibujar_iconos(info);
}


void AreaDeJuego2D::resaltar_territorios_adyacentes(Territorio* territorio){
	foreach(IteradorIconos, i, this->iconos){
		Tropa* tropa = (*i)->get_tropa();
		(*i)->set_iluminacion(tropa->get_territorio()->es_adyacente_a(territorio));
	}
}


void AreaDeJuego2D::quitar_resaltado_de_territorios(){
	foreach(IteradorIconos, i, this->iconos){
		Tropa* tropa = (*i)->get_tropa();
		(*i)->set_iluminacion(false);
	}
}


void AreaDeJuego2D::destruir_iconos(){
	foreach(IteradorIconos, i, this->iconos){
		delete *i;
	}
	iconos = ContenedorIconos();
}


void AreaDeJuego2D::dibujar_iconos(InfoJuego* info){
	foreach(IteradorImperios, imperio, info->get_imperios()){
		foreach(IteradorTropas, t, (*imperio)->get_tropas()){
			Tropa* tropa = *t;
			Coordenada posicion = tropa->get_territorio()->get_posicion();
			Territorio* territorio = tropa->get_territorio();
			ColorImperio color = (*imperio)->get_color();
			this->dibujar_icono(tropa, posicion, color);
		}
	}
}

void AreaDeJuego2D::dibujar_icono(Tropa* tropa, Coordenada posicion, ColorImperio color){
	int x = (posicion.get_x() * ANCHO_AREA_DE_JUEGO) / this->ancho_original;
	int y = (posicion.get_y() * ALTO_AREA_DE_JUEGO) / this->alto_original;

	string ruta_icono;
	string ruta_icono_iluminado;
	switch(color){
	case ROJO:
		ruta_icono = RUTA_ICONO_IMPERIO_ROJO;
		ruta_icono_iluminado = RUTA_ICONO_IMPERIO_ROJO_RESALTADO;
		break;
	case VERDE:
		ruta_icono = RUTA_ICONO_IMPERIO_VERDE;
		ruta_icono_iluminado = RUTA_ICONO_IMPERIO_VERDE_RESALTADO;
		break;
	case AZUL:
		ruta_icono = RUTA_ICONO_IMPERIO_AZUL;
		ruta_icono_iluminado = RUTA_ICONO_IMPERIO_AZUL_RESALTADO;
		break;
	case NARANJA:
		ruta_icono = RUTA_ICONO_IMPERIO_NARANJA;
		ruta_icono_iluminado = RUTA_ICONO_IMPERIO_NARANJA_RESALTADO;
		break;
	case ROSA:
		ruta_icono = RUTA_ICONO_IMPERIO_ROSA;
		ruta_icono_iluminado = RUTA_ICONO_IMPERIO_ROSA_RESALTADO;
		break;
	case TURQUESA:
		ruta_icono = RUTA_ICONO_IMPERIO_TURQUESA;
		ruta_icono_iluminado = RUTA_ICONO_IMPERIO_TURQUESA_RESALTADO;
		break;
	}

	IconoTerritorio*  icono = new IconoTerritorio(tropa, &this->controlador, ruta_icono, ruta_icono_iluminado);
	gtk_layout_put(GTK_LAYOUT(this->layout), icono->get_widget(), x - (ANCHO_ICONO / 2), y - (ALTO_ICONO / 2));
	this->iconos.push_back(icono);
}

void AreaDeJuego2D::mostrar_imagen(string ruta_archivo){
	if(!this->imagen_activa){
		gdk_pixbuf_get_file_info (ruta_archivo.c_str(), &ancho_original, &alto_original);

		this->pixbuf = gdk_pixbuf_new_from_file_at_scale(ruta_archivo.c_str(), ANCHO_AREA_DE_JUEGO, ALTO_AREA_DE_JUEGO, false, NULL);
		imagen = gtk_image_new_from_pixbuf(this->pixbuf);

		gtk_container_add(GTK_CONTAINER(this->caja_de_eventos), this->imagen);
		gtk_container_add(GTK_CONTAINER(this->layout), this->caja_de_eventos);
		
		gtk_widget_show_all(this->layout);
		this->imagen_activa = true;
	}
}


/* Definicion de callbacks. */

void AreaDeJuego2D::on_evento_clicked(GtkWidget* widget, GdkEventButton* evento, gpointer data){
	AreaDeJuego2D* instancia = (AreaDeJuego2D*)data;
	instancia->controlador.manejar_evento_territorio_deseleccionado();
}
