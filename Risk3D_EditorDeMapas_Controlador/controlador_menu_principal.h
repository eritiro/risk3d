#ifndef CONTROLADOR_MENU_PRINCIPAL_H
#define CONTROLADOR_MENU_PRINCIPAL_H

#include "controlador_contexto.h"

class VistaMenuPrincipal;

class ControladorMenuPrincipal : public ControladorContexto<VistaMenuPrincipal> {	
	private:
		bool mapa_activo;

	public:
		void inicializar();


};




#endif /* CONTROLADOR_MENU_PRINCIPAL_H */
