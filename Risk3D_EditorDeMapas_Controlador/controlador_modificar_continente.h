#ifndef CONTROLADOR_MODIFICAR_CONTINENTE_H
#define CONTROLADOR_MODIFICAR_CONTINENTE_H

#include "controlador_contexto.h"
#include "utilidades_string.h"

class VistaModificarContinente;

class ControladorModificarContinente : public ControladorContexto<VistaModificarContinente> {	
	public:
		void inicializar();
		void manejar_evento_cargar_informacion_continente();
		void manejar_evento_confirmar();
		void manejar_evento_cancelar();
};


#endif /* CONTROLADOR_MODIFICAR_CONTINENTE_H */