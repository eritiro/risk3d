#ifndef MANEJADOR_MENSAJE_ACTUALIZACION_H_
#define MANEJADOR_MENSAJE_ACTUALIZACION_H_

#include "manejador_de_mensajes.h"
#include "actualizacion.h"

class ManejadorMensajeActualizacion : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			Actualizacion& actualizacion = dynamic_cast<Actualizacion&>(mensaje);
			InfoJuego* info = actualizacion.get_info();
			Imperio* imperio = info->get_imperio(controlador.get_contexto()->get_id_imperio());
			controlador.get_vista().actualizar(info, imperio);	
		}
};

#endif /* MANEJADOR_MENSAJE_ACTUALIZACION_H_ */
