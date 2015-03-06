#ifndef VISTA_PANTALLA_JUEGO_H_
#define VISTA_PANTALLA_JUEGO_H_

#include "vista_contexto.h"
#include "controlador_pantalla_juego.h"
#include "imperio.h"
#include "info_juego.h"

class VistaPantallaJuego : public VistaContexto<ControladorPantallaJuego> {
	public:			
		VistaPantallaJuego(ContextoJuego* contexto) : VistaContexto<ControladorPantallaJuego>(contexto){}

		virtual void mostrar_instruccion(string mensaje) = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void mostrar_mensaje_de_sistema(string mensaje) = 0;
		virtual void mostrar_mensaje_de_chat(Imperio* imperio, string mensaje) = 0;
		virtual void mostrar_batalla(Territorio* agresor, int agresores_caidos, 
									 Territorio* agredido, int defensores_caidos) = 0;
		virtual string preguntar(string pregunta) = 0;
		virtual void actualizar(InfoJuego* info, Imperio* imperio) = 0;
		virtual void resaltar_territorios_adyacentes(Territorio* territorio) = 0;
		virtual void quitar_resaltado_de_territorios() = 0;
		virtual void cerrar() = 0;
		virtual void abrir_ventana_acerca_de() = 0;
		
		virtual void cambiar_modo_vista(InfoJuego* info) = 0;
		virtual void abrir_ventana_mostrar_objetivo(string objetivo) = 0;
};

#endif /* VISTA_PANTALLA_JUEGO_H_ */
