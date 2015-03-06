#ifndef CONTROLADOR_PANTALLA_SELECCION_DE_IMPERIO_H_
#define CONTROLADOR_PANTALLA_SELECCION_DE_IMPERIO_H_

#include "controlador_contexto.h"
#include "servidor_remoto.h"

class VistaPantallaSeleccionDeImperio;

class ControladorPantallaSeleccionDeImperio : public ControladorContexto<VistaPantallaSeleccionDeImperio> {	
	public:
		void inicializar();
		void manejar_evento_temporizador();
		void manejar_evento_aceptar();
		void manejar_evento_cancelar();
};


#endif /* CONTROLADOR_PANTALLA_SELECCION_DE_IMPERIO_H_ */
