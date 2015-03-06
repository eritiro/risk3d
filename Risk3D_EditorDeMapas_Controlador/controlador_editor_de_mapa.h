#ifndef RISK3D_CONTROLADOR_EDITOR_DE_MAPA_H
#define RISK3D_CONTROLADOR_EDITOR_DE_MAPA_H

#include "controlador_contexto.h"
#include "estrategia_de_edicion.h"
#include "estrategia_edicion_territorio.h"
#include "estrategia_edicion_adyacencia.h"
#include "estrategia_eliminar_territorio.h"
#include "estrategia_sin_seleccion.h"
#include "escritor_de_xml.h"
#include "serializador_mapa.h"
#include "lector_de_xml.h"


class VistaEditorDeMapa;

class ControladorEditorDeMapa : public ControladorContexto<VistaEditorDeMapa> {	
	private:
		EstrategiaDeEdicion* estrategia_de_edicion;
		void guardar_mapa();
		string ruta_archivo;

		Mapa* leer_mapa(string nombre_archivo);

	public:
		~ControladorEditorDeMapa();
		
		void inicializar();

		void manejar_evento_destruir_ventana_principal();

		void manejar_destruir_ventana();
		void manejar_evento_nuevo_mapa();
		void manejar_evento_abrir_mapa();
		void manejar_evento_guardar_mapa();
		void manejar_evento_guardar_como_mapa();
		void manejar_evento_cerrar_mapa();
		void manejar_evento_salir_editor();

		void manejar_evento_crear_continente();
		void manejar_evento_modificar_continente();
		void manejar_evento_eliminar_continente();

		void manejar_evento_edicion(int x, int y);
		void manejar_evento_edicion(Territorio* territorio);

		void manejar_evento_modo_editar_territorio();
		void manejar_evento_modo_editar_adyacencias();
		void manejar_evento_modo_eliminar_territorio();

		void manejar_evento_administrar_objetivos();
		void manejar_evento_mostrar_acerca_de();
};


#endif /* RISK3D_CONTROLADOR_EDITOR_DE_MAPA_H */
