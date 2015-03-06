#ifndef ESTRATEGIA_DE_JUEGO_H_
#define ESTRATEGIA_DE_JUEGO_H_

#include "controlador_pantalla_juego.h"
#include "vista_pantalla_juego.h"

class EstrategiaDeJuego {	
	public:
		virtual void inicializar_estrategia(ControladorPantallaJuego* controlador) = 0;
		virtual void manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio) = 0;
		virtual void manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador) = 0;
};

#endif /* ESTRATEGIA_DE_JUEGO_H_ */
