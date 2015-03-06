#ifndef CONTROLADOR_PANTALLA_PRINCIPAL_H_
#define CONTROLADOR_PANTALLA_PRINCIPAL_H_

#include "controlador_contexto.h"

class VistaPantallaPrincipal;

class ControladorPantallaPrincipal : public ControladorContexto<VistaPantallaPrincipal> {	
	public:
		void inicializar();
		void manejar_evento_destruir_ventana_principal();
		void manejar_evento_crear_juego();
		void manejar_evento_unirse_a_juego();
		void manejar_evento_salir();
};


#endif /* CONTROLADOR_PANTALLA_PRINCIPAL_H_ */
