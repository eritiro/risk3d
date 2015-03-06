#ifndef ESTRATEGIA_SIN_SELECCION_H_
#define ESTRATEGIA_SIN_SELECCION_H_

#include "estrategia_de_edicion.h"


class EstrategiaSinSeleccion : public EstrategiaDeEdicion {
	public:
		EstrategiaSinSeleccion(){}
		~EstrategiaSinSeleccion(){}
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Coordenada coordenada);
		void efectuar_edicion(ControladorEditorDeMapa* controlador, Territorio* territorio);
};


#endif /* ESTRATEGIA_SIN_SELECCION_H_ */ 