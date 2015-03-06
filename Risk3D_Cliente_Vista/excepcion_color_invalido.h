#ifndef EXCEPCION_COLOR_INVALIDO_H_
#define EXCEPCION_COLOR_INVALIDO_H_

#include "excepcion_risk3d.h"

class ExcepcionColorInvalido : public ExcepcionRisk3D {
	public:
		ExcepcionColorInvalido(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionColorInvalido(){
		}
};


#endif /* EXCEPCION_COLOR_INVALIDO_H_ */
