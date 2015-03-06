#ifndef VISTA_H_
#define VISTA_H_

#include "controlador.h"

template<class T> class Vista {
	private:
		T* controlador;

	public:
		Vista(){
			controlador = new T();
			((ControladorBase*)controlador)->set_vista(this);
		}

		Vista(void* contexto){
			controlador = new T();
			((ControladorBase*)controlador)->set_vista(this);
			((ControladorBase*)controlador)->set_contexto(contexto);
		}

		virtual ~Vista()
		{
			delete controlador;
		}

		T& get_controlador() const{ 
			return *controlador; 
		}
};

#endif /* VISTA_H_ */
