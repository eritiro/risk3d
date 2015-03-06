#ifndef ESTRATEGIA_REAGRUPACION_H_
#define ESTRATEGIA_REAGRUPACION_H_

#include "estrategia_de_juego.h"

class EstrategiaReagrupacion : public EstrategiaDeJuego {
	private:
		Territorio* desde;
		bool selecciono_origen;

	public:
		void inicializar_estrategia(ControladorPantallaJuego* controlador);
		void manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio);
		void manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador);
};

#endif /* ESTRATEGIA_REAGRUPACION_H_ */
