#ifndef REPARTIDOR_DE_OBJETIVOS_H_
#define REPARTIDOR_DE_OBJETIVOS_H_

#include "log.h"
#include "configuracion_mapa.h"
#include "ambiente_de_juego.h"
#include "jugador.h"
#include "objetivo_de_ocupacion.h"
#include "objetivo_de_destruccion.h"
#include "fabrica_de_mensajes.h"

class RepartidorDeObjetivos {
	private:
		ConfiguracionMapa& configuracion;
		AmbienteDeJuego& ambiente;
		InfoJuego& info;

		ContenedorObjetivos crear_objetivos_de_ocupacion(ContenedorRequisitos requisitos);
		void agregar_objetivos_de_destruccion(ContenedorObjetivos& objetivos, ContenedorJugadores& jugadores);
		void asignar_objetivo(Jugador* jugador, ContenedorObjetivos& objetivos);
		Objetivo* buscar_objetivo(Jugador* jugador, ContenedorObjetivos& objetivos);
	public:
		RepartidorDeObjetivos(ConfiguracionMapa& configuracion, AmbienteDeJuego& ambiente, InfoJuego& info);
		void repartir_objetivos(ContenedorJugadores& jugadores);
};


#endif /* REPARTIDOR_DE_OBJETIVOS_H_ */
