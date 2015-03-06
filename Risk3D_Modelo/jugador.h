#ifndef JUGADOR_H_
#define JUGADOR_H_

#pragma warning(disable:4786)

#include "imperio.h"
#include "excepcion_de_usuario.h"
#include "info_juego.h"
#include "mensaje.h"
#include "objetivo.h"

class Jugador;

typedef std::vector<Jugador*> ContenedorJugadores;
typedef ContenedorJugadores::iterator IteradorJugadores;

class Jugador {
	private:
		Imperio* imperio;
		Objetivo* objetivo;
	public:
		Jugador();
		virtual ~Jugador();

		Imperio* get_imperio();
		void set_imperio(Imperio* valor);
		Objetivo* get_objetivo();
		void set_objetivo(Objetivo* valor);

		string get_nombre_emperador();

		
		virtual void recibir_mensaje(Mensaje* mensaje) = 0;
};


#endif /* JUGADOR_H_ */
