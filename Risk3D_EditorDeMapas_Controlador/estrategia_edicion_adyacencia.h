#ifndef ESTRATEGIA_EDICION_ADYACENCIA_H_
#define ESTRATEGIA_EDICION_ADYACENCIA_H_

#include "estrategia_de_edicion.h"

class EstrategiaEdicionAdyacencia : public EstrategiaDeEdicion {
	private:
		Territorio* territorio_seleccionado;
	public:
		EstrategiaEdicionAdyacencia();
		~EstrategiaEdicionAdyacencia();
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada);
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio);
};

#endif /* ESTRATEGIA_EDICION_ADYACENCIA_H_ */