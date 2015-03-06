#ifndef REPARTIDOR_DE_TERRITORIOS_H_
#define REPARTIDOR_DE_TERRITORIOS_H_

#include "juego.h"

class RepartidorDeTerritorios {
	private:
		void asignar_territorio(Juego* juego, Territorio* territorio);
		
	public:
		void repartir_territorios(Juego* juego);
};


#endif /* REPARTIDOR_DE_TERRITORIOS_H_ */
