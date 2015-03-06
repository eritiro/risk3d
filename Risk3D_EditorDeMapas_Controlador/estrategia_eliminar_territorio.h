#ifndef ESTRATEGIA_ELIMINAR_TERRITORIO_H_
#define ESTRATEGIA_ELIMINAR_TERRITORIO_H_

#include "estrategia_de_edicion.h"

class EstrategiaEliminarTerritorio : public EstrategiaDeEdicion {
	public:
		EstrategiaEliminarTerritorio();
		~EstrategiaEliminarTerritorio();
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada);
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio);
};

#endif /* ESTRATEGIA_ELIMINAR_TERRITORIO_H_ */