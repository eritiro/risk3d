#ifndef ORDEN_AGREGAR_JUGADOR_H_
#define ORDEN_AGREGAR_JUGADOR_H_

#include "orden.h"
#include "color_imperio.h"

class OrdenAgregarJugador : public Orden {
	private:
		string nombre;
		ColorImperio color;
		bool creador_del_juego;
		
	public:
		OrdenAgregarJugador(string nombre, ColorImperio color, bool es_creador_del_juego);
		string get_nombre();
		ColorImperio get_color();
		bool es_creador_del_juego();
};


#endif /* ORDEN_AGREGAR_JUGADOR_H_ */
