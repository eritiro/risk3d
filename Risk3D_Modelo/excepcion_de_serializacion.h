#ifndef EXCEPCION_DE_SERIALIZACION_H_
#define EXCEPCION_DE_SERIALIZACION_H_

#include "excepcion_risk3d.h"

class ExcepcionDeSerializacion : public ExcepcionRisk3D {
	public:
		ExcepcionDeSerializacion(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionDeSerializacion(){
		}
};


#endif /* EXCEPCION_DE_SERIALIZACION_H_ */
