#ifndef ESTRATEGIA_SIN_SELECCION_H_
#define ESTRATEGIA_SIN_SELECCION_H_

#include "estrategia_de_juego.h"

class EstrategiaSinSeleccion : public EstrategiaDeJuego {	
	public:
		void inicializar_estrategia(ControladorPantallaJuego* controlador);
		void manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio);
		void manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador);
};

#endif /* ESTRATEGIA_SIN_SELECCION_H_ */
