#ifndef INFO_JUEGO_H_
#define INFO_JUEGO_H_

#include "mapa.h"
#include "imperio.h"
#include "tranferible.h"

typedef std::vector<Imperio*> ContenedorImperios;
typedef ContenedorImperios::iterator IteradorImperios;

class InfoJuego : public Tranferible {
	private:
		Mapa& mapa;
		ContenedorImperios imperios;
	public:
		InfoJuego(Mapa& mapa);
		~InfoJuego();
		Mapa& get_mapa();
		ContenedorImperios& get_imperios();
		Imperio* get_imperio(int id);
		Imperio* get_propietario(Territorio* territorio);
		Tropa* get_tropa(Territorio* territorio);
};


#endif /* INFO_JUEGO_H_ */
