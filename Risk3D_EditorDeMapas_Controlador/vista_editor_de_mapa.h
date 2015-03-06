#ifndef VISTA_EDITOR_DE_MAPA_H_
#define VISTA_EDITOR_DE_MAPA_H_

#include <string>
#include "vista_contexto.h"
#include "controlador_editor_de_mapa.h"

using namespace std;

class VistaEditorDeMapa : public VistaContexto<ControladorEditorDeMapa> {
	public:
		VistaEditorDeMapa(ContextoEditor* contexto) : VistaContexto<ControladorEditorDeMapa>(contexto){}

		virtual void mostrar_mensaje_barra_estado(string mensaje) = 0;
		virtual void mostrar_mensaje_alerta(string mensaje) = 0;

		virtual string solicitar_archivo(string descripcion) = 0;
		virtual void mostrar_textura(string archivo) = 0;
		virtual void ocultar_textura() = 0;
		
		virtual void abrir_ventana_crear_continente() = 0;
		virtual void abrir_ventana_modificar_continente() = 0;
		virtual void abrir_ventana_eliminar_continente() = 0;
		
		virtual void abrir_ventana_edicion_territorio() = 0;

		virtual void destruir_ventana_principal() = 0;

		virtual void refrescar_mapa(Mapa* mapa) = 0;
		virtual void refrescar_mapa(Mapa* mapa, Territorio* territorio_seleccionado) = 0;

		virtual void abrir_ventana_administrar_objetivos() = 0;
		virtual void abrir_ventana_acerca_de() = 0;

		virtual bool elegir_respuesta(string descripcion) = 0;
};

#endif
