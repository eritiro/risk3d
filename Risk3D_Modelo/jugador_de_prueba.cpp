#include "jugador_de_prueba.h"

static Log log("JugadorDePrueba");

void JugadorDePrueba::recibir_mensaje(Mensaje* mensaje){
	log.info(this->get_nombre_emperador() + " << " + mensaje->get_descripcion());
	delete mensaje;
}
