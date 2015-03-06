#ifndef EXCEPCION_SOCKET_INVALIDO_H_
#define EXCEPCION_SOCKET_INVALIDO_H_

#include "excepcion_socket_invalido.h"

class ExcepcionSocketInvalido : public ExcepcionDeSocket {
	public:
		ExcepcionSocketInvalido() 
			: ExcepcionDeSocket("No se pueden recibir datos cuando el socket se encuentra cerrado."){
		}
		virtual ~ExcepcionSocketInvalido(){
		}
};


#endif /* EXCEPCION_SOCKET_INVALIDO_H_ */
