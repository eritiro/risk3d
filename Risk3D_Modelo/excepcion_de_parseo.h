#ifndef EXCEPCION_DE_PARSEO_H_
#define EXCEPCION_DE_PARSEO_H_

#include "excepcion_risk3d.h"

class ExcepcionDeParseo : public ExcepcionRisk3D {
	public:
		ExcepcionDeParseo(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionDeParseo(){
		}
};

#endif /* EXCEPCION_DE_PARSEO_H_ */
