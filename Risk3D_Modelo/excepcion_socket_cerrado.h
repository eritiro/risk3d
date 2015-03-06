#ifndef EXCEPCION_SOCKET_CERRADO_H_
#define EXCEPCION_SOCKET_CERRADO_H_

#include "excepcion_de_socket.h"

class ExcepcionSocketCerrado : public ExcepcionDeSocket {
	public:
		ExcepcionSocketCerrado() : ExcepcionDeSocket("Se cerro el socket"){
		}
		virtual ~ExcepcionSocketCerrado(){
		}
};


#endif /* EXCEPCION_SOCKET_CERRADO_H_ */
