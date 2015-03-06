#ifndef ACTUALIZACION_H_
#define ACTUALIZACION_H_

#include "mensaje.h"
#include "info_juego.h"
#include "ciclo_de_vida.h"

class Actualizacion : public Mensaje, public CicloDeVida {		
	InfoJuego* info;
	public:
		Actualizacion(InfoJuego* info): Mensaje(TipoDeMensaje::actualizacion()), info(info){
		};

		InfoJuego* get_info(){
			return info;
		}
};


#endif /* ACTUALIZACION_H_ */
