#ifndef JUGADOR_REMOTO_H_
#define JUGADOR_REMOTO_H_

#include "jugador.h"
#include "socket.h"
#include "hilo_envio.h"
#include "hilo_recepcion.h"

class ProveedorDeOrdenesRemotas;

class JugadorRemoto : public Jugador {
	private:
		HiloEnvio* hilo_envio;
		HiloRecepcion* hilo_recepcion;
		Socket* socket;
		ProveedorDeOrdenesRemotas* proveedor;
	public:
		JugadorRemoto(Socket* socket, ProveedorDeOrdenesRemotas* proveedor, Mapa* mapa);
		~JugadorRemoto();
		void recibir_mensaje(Mensaje* mensaje);
};


#endif /* JUGADOR_REMOTO_H_ */
