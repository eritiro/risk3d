#ifndef CONTEXTO_EDITOR_H_
#define CONTEXTO_EDITOR_H_

#include "mapa.h"

class ContextoEditor {
	private:
		ContextoEditor();

		//Lo defino como un objeto no copiable
		ContextoEditor& operator= (const ContextoEditor&);
		Mapa* mapa;
		bool mapa_activo;
		bool mapa_inicialmente_guardado;
		bool mapa_modificado;
		Coordenada coordenada_actual;
		Territorio* territorio_actual;
		bool es_territorio_nuevo;
		bool es_nuevo_requisito;
		RequisitoDeOcupacion* requisito_seleccionado;


	public:
		//Este metodo debe ser invocado para crear un nuevo contexto.
		static ContextoEditor CrearContexto();

		//Aca va todo lo que necesito que compartan mis controladores del editor de mapas:
		Mapa& get_mapa();
		void set_mapa(Mapa* mapa);
		bool hay_mapa_activo();
		void set_mapa_activo(bool value);
		void set_mapa_modificado(bool value);
		bool fue_modificado_mapa();
		void set_mapa_inicialmente_guardado(bool value);
		bool fue_guardado_inicialmente_mapa();
		void set_coordenada_actual(Coordenada coordenada);
		Coordenada get_coordenada_actual();
		void set_territorio_actual(Territorio* territorio);
		Territorio* get_territorio_actual();
		void set_es_territorio_nuevo(bool value);
		bool get_es_territorio_nuevo();
		void set_es_nuevo_requisito(bool value);
		bool get_es_nuevo_requisito();
		void set_requisito_seleccionado(RequisitoDeOcupacion* requisito);
		RequisitoDeOcupacion* get_requisito_seleccionado();


};

#endif /* CONTEXTO_EDITOR_H_ */
