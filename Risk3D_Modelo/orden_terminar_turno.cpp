#include "orden_terminar_turno.h"
#include "fabrica_de_mensajes.h"

OrdenTerminarTurno::OrdenTerminarTurno() : Orden(TipoDeOrden::terminar_turno()){
}

void OrdenTerminarTurno::ejecutar(Juego* juego, Jugador* jugador){
	if(!juego->es_el_turno_de(jugador))
		throw ExcepcionOrdenInvalida();
	
	juego->get_ronda().finalizar_turno();
	juego->notificar_a_todos("Es el turno de " + juego->get_jugador_actual()->get_nombre_emperador());
	juego->get_jugador_actual()->recibir_mensaje(FabricaDeMensajes::crear_evento_comienzo_turno());

}
