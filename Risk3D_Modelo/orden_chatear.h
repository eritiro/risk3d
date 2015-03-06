#ifndef ORDEN_CHATEAR_H_
#define ORDEN_CHATEAR_H_

#include "orden.h"

class OrdenChatear : public Orden {		
	private:
		string mensaje;
	public:
		OrdenChatear(string mensaje)
			: Orden(TipoDeOrden::chatear()), mensaje(mensaje){
		};

		string get_mensaje(){
			return mensaje;
		}
};

#endif /* ORDEN_CHATEAR_H_ */
