#ifndef CONTROLADOR_EDICION_TERRITORIO_H_
#define CONTROLADOR_EDICION_TERRITORIO_H_

#include "controlador_contexto.h"


class VistaEdicionTerritorio;

class ControladorEdicionTerritorio : public ControladorContexto<VistaEdicionTerritorio> {	
	public:
		void inicializar();
		void manejar_evento_confirmar();
		void manejar_evento_cancelar();
};


#endif /* CONTROLADOR_EDICION_TERRITORIO_H */