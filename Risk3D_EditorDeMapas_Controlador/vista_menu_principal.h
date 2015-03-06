#ifndef VISTA_MENU_PRINCIPAL_H_
#define VISTA_MENU_PRINCIPAL_H_

#include "vista_contexto.h"
#include "controlador_menu_principal.h"
#include <string>

using namespace std;

class VistaMenuPrincipal : public VistaContexto<ControladorMenuPrincipal> {
	public:
		VistaMenuPrincipal(ContextoEditor* contexto) : VistaContexto<ControladorMenuPrincipal>(contexto){
		}

};

#endif /* VISTA_MENU_PRINCIPAL_H_ */