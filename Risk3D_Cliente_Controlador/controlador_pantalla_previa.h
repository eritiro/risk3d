#ifndef CONTROLADOR_PANTALLA_PREVIA_H_
#define CONTROLADOR_PANTALLA_PREVIA_H_

#include "controlador_contexto.h"
#include "log.h"
#include "mensaje_de_sistema.h"
#include "mensaje_de_error.h"
#include "mensaje_de_chat.h"
#include "fabrica_de_ordenes.h"

class VistaPantallaPrevia;

class ControladorPantallaPrevia : public ControladorContexto<VistaPantallaPrevia> {	
	public:
		void inicializar();
		void manejar_evento_temporizador();
		void manejar_evento_chat(string mensaje);
		void manejar_evento_comenzar_juego();
		void manejar_evento_salir();
};

#endif /* #define CONTROLADOR_PANTALLA_PREVIA_H_ */
