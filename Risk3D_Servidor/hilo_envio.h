#ifndef HILO_ENVIO_H_
#define HILO_ENVIO_H_

#pragma warning(disable:4786)
#include <queue>
#include <iostream>
#include <fstream>
#include "thread.h"
#include "serializador_mensaje.h"
#include "lock.h"
#include "socket.h"
#include "constantes.h"
#include "escritor_de_xml.h"
#include "log.h"
#include "serializador_mapa.h"

using std::queue;

#define BUFFER_LECTURA_ARCHIVO 16 * 1024 * 1024

class HiloEnvio : public Thread {
	private:
		Socket* socket;
		Mutex mutex;
		Mapa* mapa;
		SerializadorMensaje serializador;
		queue<Mensaje*> mensajes;
		Mensaje* desencolar();
		void enviar_mapa();
	protected:
		void ejecutar();
	public:
		HiloEnvio(Socket* socket, Mapa* mapa);
		void encolar_para_envio(Mensaje* mensaje);
};

#endif /* HILO_ENVIO_H_ */
