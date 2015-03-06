#ifndef CONTROLADOR_CREAR_CONTINENTE_H
#define CONTROLADOR_CREAR_CONTINENTE_H

#include "controlador_contexto.h"
#include "excepcion_de_negocio.h"
#include "utilidades_string.h"

class VistaCrearContinente;

class ControladorCrearContinente : public ControladorContexto<VistaCrearContinente> {	
	public:
		void inicializar();
		void manejar_evento_confirmar();
		void manejar_evento_cancelar();
};

#endif /* CONTROLADOR_CREAR_CONTINENTE_H */