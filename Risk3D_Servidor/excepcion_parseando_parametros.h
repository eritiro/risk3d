#ifndef EXCEPCION_PARSEANDO_PARAMETROS_H_
#define EXCEPCION_PARSEANDO_PARAMETROS_H_

#include "excepcion_risk3d.h"

class ExcepcionParseandoParametros : public ExcepcionRisk3D {
	public:
		ExcepcionParseandoParametros(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionParseandoParametros(){
		}
};

#endif /* EXCEPCION_PARSEANDO_PARAMETROS_H_ */
