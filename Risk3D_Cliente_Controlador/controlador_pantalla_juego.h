#ifndef CONTROLADOR_PANTALLA_JUEGO_H_
#define CONTROLADOR_PANTALLA_JUEGO_H_

#pragma warning(disable:4786)
#include <map>
#include "fabrica_de_ordenes.h"
#include "controlador_contexto.h"
#include "log.h"
#include "mensaje.h"
#include "excepcion_de_negocio.h"

class VistaPantallaJuego;
class ManejadorDeMensajes;
class EstrategiaDeJuego;

typedef std::map<string, ManejadorDeMensajes*> TablaManejadoresDeMensajes;
typedef TablaManejadoresDeMensajes::iterator IteradorManejadoresDeMensajes;

class ControladorPantallaJuego: public ControladorContexto<VistaPantallaJuego> {	
	private:
		TablaManejadoresDeMensajes tablaManejadoresDeMensajes;
		EstrategiaDeJuego* estrategia_de_juego;
		string objetivo_secreto;

		void registrar_manejador(TipoDeMensaje tipo, ManejadorDeMensajes* manejador);
		void manejar_mensaje(Mensaje* mensaje);
		void cambiar_estrategia(EstrategiaDeJuego* estrategia);
	public:
		ControladorPantallaJuego();
		~ControladorPantallaJuego();
		void set_objetivo_secreto(string valor);

		void inicializar();
		void manejar_evento_reforzar();
		void manejar_evento_atacar();
		void manejar_evento_reagrupar();
		void manejar_evento_territorio_seleccionado(Territorio* territorio);
		void manejar_evento_territorio_deseleccionado();
		void manejar_evento_fin_de_turno();
		void manejar_evento_chat(string mensaje);
		void manejar_evento_temporizador();
		void manejar_evento_mostrar_acerca_de();
		void manejar_evento_mostrar_objetivo();
		void manejar_evento_cambiar_modo_vista();


};

#endif /* CONTROLADOR_PANTALLA_JUEGO_H_ */
