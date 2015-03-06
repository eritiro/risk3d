#include "orden_reforzar_territorio.h"
#include "juego.h"

OrdenReforzarTerritorio::OrdenReforzarTerritorio(Territorio* territorio, int cantidad_ejercitos)
	: Orden(TipoDeOrden::reforzar_territorio()), territorio(territorio), cantidad_ejercitos(cantidad_ejercitos){
}

void OrdenReforzarTerritorio::ejecutar(Juego* juego, Jugador* jugador){
	Imperio* imperio = jugador->get_imperio();

	if(!juego->es_el_turno_de(jugador))
		throw ExcepcionOrdenInvalida();
	if(cantidad_ejercitos < 0)
		throw ExcepcionDeUsuario("No se puede matar a una población.");
	if(!imperio->es_propietario_de(territorio))
		throw ExcepcionDeUsuario("El territorio no pertenece a su imperio.");
	if(imperio->get_ejercitos_disponibles() < cantidad_ejercitos)
		throw ExcepcionDeUsuario("No tiene suficientes ejercitos disponibles en su imperio.");

	Tropa* tropa = imperio->get_tropa(territorio);
	tropa->agregar_ejercitos(cantidad_ejercitos);
	imperio->agregar_ejercitos_disponibles(-cantidad_ejercitos);
	juego->notificar_a_todos(jugador->get_nombre_emperador() 
		+ " reforzo " + territorio->get_nombre() 
		+ " con " + UtilidadesString::int_a_string(cantidad_ejercitos)
		+ " ejercitos.");

	juego->actualizar();
}

Territorio* OrdenReforzarTerritorio::get_territorio(){
	return this->territorio;
}

int OrdenReforzarTerritorio::get_cantidad_ejercitos(){
	return this->cantidad_ejercitos;
}
