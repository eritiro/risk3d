#include "fabrica_de_ordenes.h"

Orden* FabricaDeOrdenes::crear_orden_agregar_jugador(string nombre, ColorImperio color, bool es_creador_del_juego){
	return new OrdenAgregarJugador(nombre, color, es_creador_del_juego);
}

Orden* FabricaDeOrdenes::crear_orden_quitar_jugador(){
	return new OrdenQuitarJugador();
}

Orden* FabricaDeOrdenes::crear_orden_comenzar_juego(){
	return new OrdenComenzarJuego();
}

Orden* FabricaDeOrdenes::crear_orden_cancelar_juego(){
	return new OrdenCancelarJuego();
}

Orden* FabricaDeOrdenes::crear_orden_terminar_turno(){
	return new OrdenTerminarTurno();
}

Orden* FabricaDeOrdenes::crear_orden_reforzar_territorio(Territorio* territorio, int ejercitos){
	return new OrdenReforzarTerritorio(territorio, ejercitos);
}

Orden* FabricaDeOrdenes::crear_orden_atacar(Territorio* origen, Territorio* destino, int ejercitos){
	return new OrdenAtacar(origen, destino, ejercitos);
}

Orden* FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(Territorio* origen, Territorio* destino, int ejercitos){
	return new OrdenReagruparEjercitos(origen, destino, ejercitos);
}

Orden* FabricaDeOrdenes::crear_orden_defender(int ejercitos){
	return new OrdenDefender(ejercitos);
}

Orden* FabricaDeOrdenes::crear_orden_chatear(string mensaje){
	return new OrdenChatear(mensaje);
}
