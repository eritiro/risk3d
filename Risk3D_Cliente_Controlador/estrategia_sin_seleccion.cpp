#include "estrategia_sin_seleccion.h"

void EstrategiaSinSeleccion::inicializar_estrategia(ControladorPantallaJuego* controlador){
	controlador->get_vista().mostrar_instruccion("Seleccione la accion a realizar");
	controlador->get_vista().quitar_resaltado_de_territorios();
}

void EstrategiaSinSeleccion::manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio){
	// no hace nada
}

void EstrategiaSinSeleccion::manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador){
	// no hace nada
}
