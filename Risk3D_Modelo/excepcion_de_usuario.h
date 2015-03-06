#ifndef EXCEPCION_DE_USUARIO_H_
#define EXCEPCION_DE_USUARIO_H_

#include "excepcion_de_negocio.h"

// Al lanzar una excepcion de tipo ExcepcionDeUsuario el juego delegará la responsabilidad de manejar a la misma
// al jugador.
// La descripcion de estas excepciones deberan ser comprensible en terminos de la dinamica del juego al usuario
// final.
class ExcepcionDeUsuario : public ExcepcionDeNegocio {
	public:
		ExcepcionDeUsuario(string descripcion) : ExcepcionDeNegocio(descripcion){
		}
		virtual ~ExcepcionDeUsuario(){
		}
};


#endif /* EXCEPCION_DE_USUARIO_H_ */
