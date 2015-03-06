#ifndef ORDEN_H_
#define ORDEN_H_

#include "tipo_de_orden.h"

class Orden {
	private:
		TipoDeOrden tipo;

	protected:
		Orden(TipoDeOrden tipo);

	public:
		virtual ~Orden();
		TipoDeOrden& get_tipo();

		// Por defecto devuelve la clave del tipo de orden, pero puede ser sobreescirta para devolver una 
		// descripcion mas especifica y con mayor información.
		virtual string get_descripcion();
		bool es_de_tipo(TipoDeOrden& tipo);
};


#endif /* ORDEN_H_ */
