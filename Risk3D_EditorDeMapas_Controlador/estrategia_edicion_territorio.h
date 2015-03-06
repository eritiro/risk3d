#ifndef ESTRATEGIA_EDICION_TERRITORIO_H_
#define ESTRATEGIA_EDICION_TERRITORIO_H_

#include "estrategia_de_edicion.h"

class EstrategiaEdicionTerritorio : public EstrategiaDeEdicion {
	public:
		EstrategiaEdicionTerritorio();
		~EstrategiaEdicionTerritorio();
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada);
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio);
};

#endif /* ESTRATEGIA_EDICION_TERRITORIO_H_ */