#ifndef CONTROLADOR_PANTALLA_SELECCION_DE_SERVIDOR_H_
#define CONTROLADOR_PANTALLA_SELECCION_DE_SERVIDOR_H_

#include "controlador_contexto.h"
#include "servidor_remoto.h"

class VistaPantallaSeleccionDeServidor;

class ControladorPantallaSeleccionDeServidor : public ControladorContexto<VistaPantallaSeleccionDeServidor> {	
	public:
		void inicializar();
		void manejar_evento_aceptar();
		void manejar_evento_cancelar();
};


#endif /* CONTROLADOR_PANTALLA_SELECCION_DE_SERVIDOR_H_ */
