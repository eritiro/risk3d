#ifndef FABRICA_DE_MENSAJES_H_
#define FABRICA_DE_MENSAJES_H_

#include "actualizacion.h"
#include "defensa_requerida.h"
#include "evento_juego_iniciado.h"
#include "evento_comienzo_turno.h"
#include "evento_juego_cancelado.h"
#include "evento_juego_terminado.h"
#include "evento_jugador_agregado.h"
#include "evento_batalla_producida.h"
#include "mensaje_de_error.h"
#include "mensaje_de_sistema.h"
#include "mensaje_de_chat.h"
#include "mensaje_objetivo_secreto.h"

// La funcion de esta clase es proveer una interfaz amena para la creacion de mensajes.
class FabricaDeMensajes {
	public:
		static Actualizacion* crear_actualizacion(InfoJuego* info);
		static Mensaje* crear_evento_comienzo_turno();		
		static Mensaje* crear_evento_juego_iniciado();
		static Mensaje* crear_evento_juego_terminado(Imperio* imperio, Objetivo* objetivo);
		static Mensaje* crear_evento_juego_terminado(Imperio* imperio, string objetivo);
		static Mensaje* crear_evento_juego_cancelado();

		static Mensaje* crear_evento_jugador_agregado(Imperio* imperio);
		static Mensaje* crear_evento_batalla_producida(Territorio* agresor, int agresores_caidos, Territorio* agredido, int defensores_caidos);
		static Mensaje* crear_mensaje_de_error(ExcepcionDeUsuario& ex);
		static Mensaje* crear_mensaje_de_error(string mensaje);
		static Mensaje* crear_mensaje_de_sistema(string mensaje);
		static Mensaje* crear_mensaje_de_chat(Imperio* imperio, string mensaje);
		static Mensaje* crear_defensa_requerida(Territorio* territorio_agresor, Territorio* territorio_agredido, int ejercitos_ataque);
		static Mensaje* crear_mensaje_objetivo_secreto(Objetivo* objetivo);
		static Mensaje* crear_mensaje_objetivo_secreto(string contenido);
};


#endif /* FABRICA_DE_ORDENES_H_ */
