#ifndef MANEJADOR_MENSAJE_DE_SISTEMA_H_
#define MANEJADOR_MENSAJE_DE_SISTEMA_H_

#include "manejador_de_mensajes.h"
#include "mensaje_de_sistema.h"

class ManejadorMensajeDeSistema : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){
			MensajeDeSistema& mensaje_de_sistema = dynamic_cast<MensajeDeSistema&>(mensaje);
			controlador.get_vista().mostrar_mensaje_de_sistema(mensaje_de_sistema.get_mensaje());	
		}
};

#endif /* MANEJADOR_MENSAJE_DE_SISTEMA_H_ */
