#ifndef CONTROLADOR_ELIMINAR_CONTINENTE_H_
#define CONTROLADOR_ELIMINAR_CONTINENTE_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el vector es un template
// "asi de grande".
#pragma warning(disable:4786)

#include <vector>
#include "controlador_contexto.h"

using std::vector;

class VistaEliminarContinente;


typedef vector<string> ContenedorNombresContinentes;
typedef ContenedorNombresContinentes::iterator IteradorNombresContinentes;

class ControladorEliminarContinente : public ControladorContexto<VistaEliminarContinente> {	
	private:
		ContenedorNombresContinentes contenedor_nombres_continentes;
		
	public:
		void inicializar();
		void manejar_evento_confirmar();
		void manejar_evento_cancelar();
		void manejar_evento_seleccionado(string nombre_continente);
		void manejar_evento_desseleccionado(string nombre_continente);
 
};


#endif /* CONTROLADOR_ELIMINAR_CONTINENTE_H_ */