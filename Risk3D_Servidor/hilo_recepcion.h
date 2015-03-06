#ifndef HILO_RECEPCION_H_
#define HILO_RECEPCION_H_

#include "thread.h"
#include "serializador_orden.h"
#include "socket.h"
#include "constantes.h"
#include "lector_de_xml.h"

class ProveedorDeOrdenesRemotas;
class JugadorRemoto;

class HiloRecepcion : public Thread {
	private:
		Socket* socket;
		ProveedorDeOrdenesRemotas* proveedor;
		JugadorRemoto* jugador;
		SerializadorOrden serializador;
	protected:
		void ejecutar();
	public:
		HiloRecepcion(Socket* socket, ProveedorDeOrdenesRemotas* proveedor, JugadorRemoto* jugador);
};

#endif /* HILO_RECEPCION_H_ */
