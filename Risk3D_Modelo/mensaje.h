#ifndef MENSAJE_H_
#define MENSAJE_H_

#pragma warning(disable:4786)

#include <list>
#include "tipo_de_mensaje.h"

class Mensaje;
typedef std::list<Mensaje*> ContenedorMensajes;
typedef ContenedorMensajes::iterator IteradorMensajes;

class Mensaje {
	private:
		TipoDeMensaje tipo;

	protected:
		Mensaje(TipoDeMensaje tipo);

	public:
		virtual ~Mensaje();
		TipoDeMensaje& get_tipo();

		// Por defecto devuelve la clave del tipo de orden, pero puede ser sobreescirta para devolver una 
		// descripcion mas especifica y con mayor información.
		virtual string get_descripcion();
		bool es_de_tipo(TipoDeMensaje& tipo);

};

#endif /* MENSAJE_H_ */
