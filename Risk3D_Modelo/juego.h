#ifndef JUEGO_H_
#define JUEGO_H_

#pragma warning(disable:4786)

#include "ambiente_normal.h"
#include "info_juego.h"
#include "log.h"
#include "estado_del_juego.h"
#include "creando_juego.h"
#include "ronda_normal.h"
#include "ciclo_de_vida.h"
#include "jugador_bot.h"

class Juego : public CicloDeVida {
	private:
		InfoJuego info;
		AmbienteDeJuego* ambiente;
		EstadoDelJuego* estado;
		Ronda* ronda;
		ContenedorJugadores jugadores;
		ContenedorBots bots;
		bool juego_terminado;
		

	public:
		Juego(Mapa& mapa);
		~Juego();
		
		InfoJuego& get_info();
		
		AmbienteDeJuego& get_ambiente();
		void set_componente_ambiente(AmbienteDeJuego* valor);

		EstadoDelJuego* get_estado();
		void set_componente_estado(EstadoDelJuego* valor);

		Ronda& get_ronda();
		void set_componente_ronda(Ronda* valor);
		
		ContenedorJugadores& get_jugadores();
		Jugador* get_creador();
		Jugador* get_jugador_actual();
		Jugador* get_jugador(Imperio* imperio);

		bool get_juego_terminado();
		void terminar_juego();

		void procesar(Orden* orden, Jugador* jugador);
		void notificar_a_todos(string mensaje);
		void actualizar();
		bool es_el_turno_de(Jugador* jugador);

		void agregar_bot(JugadorBot* bot);
};


#endif /* JUEGO_H_ */
