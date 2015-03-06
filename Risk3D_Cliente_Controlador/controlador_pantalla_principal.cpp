#include "controlador_pantalla_principal.h"
#include "vista_pantalla_principal.h"

void ControladorPantallaPrincipal::inicializar(){
	// no hace nada.
}


void ControladorPantallaPrincipal::manejar_evento_crear_juego(){
	this->get_vista().abrir_ventana_crear_juego();
}


void ControladorPantallaPrincipal::manejar_evento_unirse_a_juego(){
	this->get_vista().abrir_ventana_seleccion_servidor();
}

void ControladorPantallaPrincipal::manejar_evento_salir(){
	this->get_vista().cerrar();
}

void ControladorPantallaPrincipal::manejar_evento_destruir_ventana_principal(){
	this->get_vista().cerrar();
}