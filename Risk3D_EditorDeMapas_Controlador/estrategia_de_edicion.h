#ifndef ESTRATEGIA_DE_EDICION_H_
#define ESTRATEGIA_DE_EDICION_H_

#include "coordenada.h"
#include "territorio.h"

class ControladorEditorDeMapa;

class EstrategiaDeEdicion {	
	public:
		virtual void efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada) = 0;
		virtual void efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio) = 0;
		virtual ~EstrategiaDeEdicion(){
		}
};


#endif /* ESTRATEGIA_DE_EDICION_H_ */