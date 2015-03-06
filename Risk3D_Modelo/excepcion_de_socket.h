#ifndef EXCEPCION_DE_SOCKET_H_
#define EXCEPCION_DE_SOCKET_H_

#include "excepcion_risk3d.h"

class ExcepcionDeSocket : public ExcepcionRisk3D {
	public:
		ExcepcionDeSocket(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionDeSocket(){
		}
};


#endif /* EXCEPCION_DE_SOCKET_H_ */
