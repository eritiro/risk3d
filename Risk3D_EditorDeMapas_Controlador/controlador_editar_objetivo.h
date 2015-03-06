#ifndef CONTROLADOR_EDITAR_OBJETIVO_H_
#define CONTROLADOR_EDITAR_OBJETIVO_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el vector es un template
// "asi de grande".
#pragma warning(disable:4786)

#include <vector>
#include "controlador_contexto.h"


using std::vector;

class VistaEditarObjetivo;


class ControladorEditarObjetivo : public ControladorContexto<VistaEditarObjetivo> {	
	private:
		ContenedorContinentes* contenedor_continentes;

	public:
		void inicializar();
		void manejar_evento_aceptar();
		void manejar_evento_cancelar();
		
};


#endif /* CONTROLADOR_EDITAR_OBJETIVO_H_ */