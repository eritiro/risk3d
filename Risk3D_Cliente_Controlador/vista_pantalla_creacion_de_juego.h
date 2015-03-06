#ifndef VISTA_PANTALLA_CREACION_DE_JUEGO_H_
#define VISTA_PANTALLA_CREACION_DE_JUEGO_H_

#include "vista_contexto.h"
#include "controlador_pantalla_creacion_de_juego.h"

class VistaPantallaCreacionDeJuego: public VistaContexto<ControladorPantallaCreacionDeJuego> {
	public:			
		VistaPantallaCreacionDeJuego(ContextoJuego* contexto) : VistaContexto<ControladorPantallaCreacionDeJuego>(contexto){}
		
		virtual string solicitar_archivo(string descripcion) = 0;
		virtual void mostrar_seleccion_de_imperio() = 0;
		virtual void mostrar_alerta(string mensaje) = 0;
		virtual void cerrar() = 0;
		
		virtual string get_ruta_mapa_seleccionado() = 0;
		virtual void set_ruta_mapa_seleccionado(string valor) = 0;
		
		virtual string get_puerto() = 0;
};

#endif /* VISTA_PANTALLA_CREACION_DE_JUEGO_H_ */
