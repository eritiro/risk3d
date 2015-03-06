#ifndef MANEJADOR_MENSAJE_JUEGO_TERMINADO_H_
#define MANEJADOR_MENSAJE_JUEGO_TERMINADO_H_

#include "manejador_de_mensajes.h"

class ManejadorMensajeJuegoTerminado : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			EventoJuegoTerminado& evento_juego_terminado = dynamic_cast<EventoJuegoTerminado&>(mensaje);
			Imperio* imperio_ganador = evento_juego_terminado.get_imperio_ganador();
			string objetivo = evento_juego_terminado.get_objetivo();
			
			controlador.get_vista().mostrar_instruccion("Fin del juego.");
			controlador.get_vista().mostrar_mensaje_de_sistema(imperio_ganador->get_nombre_emperador() + " tenia el siguiente objetivo: \n" + objetivo);
		}
};

#endif /* MANEJADOR_MENSAJE_JUEGO_TERMINADO_H_ */
