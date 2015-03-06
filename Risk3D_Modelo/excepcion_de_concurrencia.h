#ifndef EXCEPCION_DE_CONCURRENCIA_H_
#define EXCEPCION_DE_CONCURRENCIA_H_

#include "excepcion_risk3d.h"

class ExcepcionDeConcurrencia : public ExcepcionRisk3D {
	public:
		ExcepcionDeConcurrencia(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionDeConcurrencia(){
		}
};


#endif /* EXCEPCION_DE_CONCURRENCIA_H_ */
