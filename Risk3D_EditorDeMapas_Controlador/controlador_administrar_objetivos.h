#ifndef CONTROLADOR_ADMINISTRAR_OBJETIVOS_H_
#define CONTROLADOR_ADMINISTRAR_OBJETIVOS_H_

#pragma warning(disable:4786)

#include <vector>
#include "controlador_contexto.h"


using std::vector;

class VistaAdministrarObjetivos;

typedef vector<RequisitoDeOcupacion*> ContenedorRequisitos;
typedef ContenedorRequisitos::iterator IteradorRequisitos;


class ControladorAdministrarObjetivos : public ControladorContexto<VistaAdministrarObjetivos> {	
	private:
		ContenedorRequisitos contenedor_nombres_objetivos;

	public:
		void inicializar();
		void manejar_evento_agregar_nuevo();
		void manejar_evento_cancelar();
		void manejar_evento_modificar(RequisitoDeOcupacion* requisito);
		void manejar_evento_actualizar();
		void manejar_evento_eliminar(RequisitoDeOcupacion* requisito);
};


#endif /* CONTROLADOR_ADMINISTRAR_OBJETIVOS_H_ */