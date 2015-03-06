#ifndef ESTADO_DEL_JUEGO_H_
#define ESTADO_DEL_JUEGO_H_

#pragma warning(disable:4786)

#include "orden.h"
#include "jugador.h"
#include "excepcion_orden_invalida.h"
#include "orden_chatear.h"

class Juego;

class EstadoDelJuego {
	private:
		string descripcion;
		void quitar_jugador(Jugador* jugador, Juego* juego);

	protected:
		EstadoDelJuego(string descripcion);
		bool hay_un_ganador(Juego* juego);

	public:
		virtual ~EstadoDelJuego();
		virtual void inicializar(Juego* juego);
		virtual EstadoDelJuego* proximo_estado(Orden& orden, Jugador* jugador, Juego* juego);
		virtual string get_descripcion();
};


#endif /* ESTADO_DEL_JUEGO_H_ */
