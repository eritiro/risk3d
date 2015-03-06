#include "jugador_remoto.h"
#include "proveedor_de_ordenes_remotas.h"

JugadorRemoto::JugadorRemoto(Socket* socket, ProveedorDeOrdenesRemotas* proveedor, Mapa* mapa){
	this->socket = socket;

	hilo_envio = new HiloEnvio(socket, mapa); 
	hilo_envio->comenzar();
	
	hilo_recepcion = new HiloRecepcion(socket, proveedor, this);
	hilo_recepcion->comenzar();
}

void JugadorRemoto::recibir_mensaje(Mensaje* mensaje){
	hilo_envio->encolar_para_envio(mensaje);
}

JugadorRemoto::~JugadorRemoto(){
	// necesito asegurarme que los hilos van a dejar de intentar usar el socket
	// antes de eliminarlo.
	socket->desconectar();
	hilo_envio->unir();
	hilo_recepcion->unir();
	
	delete socket;
	delete hilo_envio;
	delete hilo_recepcion;
}
