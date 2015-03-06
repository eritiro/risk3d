#ifndef FABRICA_DE_ORDENES_H_
#define FABRICA_DE_ORDENES_H_

#include "orden.h"
#include "orden_agregar_jugador.h"
#include "orden_comenzar_juego.h"
#include "orden_cancelar_juego.h"
#include "orden_terminar_turno.h"
#include "orden_reforzar_territorio.h"
#include "orden_atacar.h"
#include "orden_reagrupar_ejercitos.h"
#include "orden_defender.h"
#include "orden_quitar_jugador.h"
#include "orden_chatear.h"

// La funcion de esta clase es proveer una interfaz amena para la creacion de ordenes.
class FabricaDeOrdenes {
	public:
		static Orden* crear_orden_agregar_jugador(string nombre, ColorImperio color, bool es_creador_del_juego);
		static Orden* crear_orden_quitar_jugador();
		static Orden* crear_orden_comenzar_juego();
		static Orden* crear_orden_cancelar_juego();
		static Orden* crear_orden_terminar_turno();
		static Orden* crear_orden_reforzar_territorio(Territorio* territorio, int ejercitos);
		static Orden* crear_orden_atacar(Territorio* origen, Territorio* destino, int ejercitos);
		static Orden* crear_orden_defender(int ejercitos);
		static Orden* crear_orden_reagrupar_ejercitos(Territorio* origen, Territorio* destino, int ejercitos);
		static Orden* crear_orden_chatear(string mensaje);
};


#endif /* FABRICA_DE_ORDENES_H_ */
