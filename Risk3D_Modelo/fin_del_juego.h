#ifndef FIN_DEL_JUEGO_H_
#define FIN_DEL_JUEGO_H_

#include "estado_del_juego.h"
#include "juego.h"

class FinDelJuego : public EstadoDelJuego {
	public:
		FinDelJuego();
		void inicializar(Juego* juego);
};


#endif /* FIN_DEL_JUEGO_H_ */
