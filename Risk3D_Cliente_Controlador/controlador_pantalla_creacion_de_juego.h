#ifndef CONTROLADOR_PANTALLA_CREACION_DE_JUEGO_H_
#define CONTROLADOR_PANTALLA_CREACION_DE_JUEGO_H_

#include "controlador_contexto.h"
#include "constantes.h"
#include "utilidades_string.h"
#include "hilo_ejecucion.h"
#include "servidor_remoto.h"

class VistaPantallaCreacionDeJuego;

class ControladorPantallaCreacionDeJuego: public ControladorContexto<VistaPantallaCreacionDeJuego> {	
	public:
		void inicializar();
		void manejar_evento_aceptar();
		void manejar_evento_cancelar();
		void manejar_evento_examinar();
};


#endif /* CONTROLADOR_PANTALLA_CREACION_DE_JUEGO_H_ */
