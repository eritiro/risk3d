#ifndef MANEJADOR_MENSAJE_BATALLA_PRODUCIDA_H_
#define MANEJADOR_MENSAJE_BATALLA_PRODUCIDA_H_

#include "manejador_de_mensajes.h"
#include "evento_batalla_producida.h"

class ManejadorMensajeBatallaProducida : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			EventoBatallaProducida& evento = dynamic_cast<EventoBatallaProducida&>(mensaje);
			controlador.get_vista().mostrar_batalla(evento.get_agresor(), evento.get_agresores_caidos(), evento.get_agredido(), evento.get_defensores_caidos());
		}
};

#endif /* MANEJADOR_MENSAJE_BATALLA_PRODUCIDA_H_ */
