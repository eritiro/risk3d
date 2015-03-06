#ifndef EXCEPCION_DE_NEGOCIO_H_
#define EXCEPCION_DE_NEGOCIO_H_

#include "excepcion_risk3d.h"

// Una excepcion de negocio es aquella producida por un intento de quebrar alguna de las reglas de negocio.
class ExcepcionDeNegocio : public ExcepcionRisk3D {
	public:
		ExcepcionDeNegocio(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionDeNegocio(){
		}
};


#endif /* EXCEPCION_DE_NEGOCIO_H_ */
