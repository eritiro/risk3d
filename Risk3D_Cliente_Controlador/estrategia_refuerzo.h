#ifndef ESTRATEGIA_REFUERZO_H_
#define ESTRATEGIA_REFUERZO_H_

#include "estrategia_de_juego.h"
#include "utilidades_string.h"

class EstrategiaRefuerzo : public EstrategiaDeJuego {	
	public:
		void inicializar_estrategia(ControladorPantallaJuego* controlador);
		void manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio);
		void manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador);
};

#endif /* ESTRATEGIA_REFUERZO_H_ */
