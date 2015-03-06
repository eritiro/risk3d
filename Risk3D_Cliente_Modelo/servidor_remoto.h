#ifndef SERVIDOR_REMOTO_H_
#define SERVIDOR_REMOTO_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el queue es un template
// "asi de grande".
#pragma warning(disable:4786)
#include <queue>
#include <fstream>
#include "servidor.h"
#include "thread.h"
#include "lock.h"
#include "socket.h"
#include "utilidades_string.h"
#include "serializador_orden.h"
#include "serializador_mensaje.h"
#include "escritor_de_xml.h"
#include "lector_de_xml.h"
#include "info_juego.h"
#include "fabrica_de_mensajes.h"
#include "serializador_mapa.h"
#include "constantes_cliente.h"

class ServidorRemoto : public Servidor, public Thread {
	private:
		SerializadorOrden serializador_orden;
		SerializadorMensaje serializador_mensaje;
		Mutex mutex;
		Socket socket;
		std::queue<string> mensajes;
		Mapa* mapa;
		InfoJuego* info;
		void agregar_mensaje_string(string mensaje);
		string get_mensaje_string();
		int mensajes_recibidos;
	protected:
		void ejecutar();

	public:
		ServidorRemoto(string servidor, int puerto);
		~ServidorRemoto();

		void enviar(Orden* orden);
		Mensaje* get_mensaje();
		InfoJuego* get_info();

		bool get_juego_terminado();
};


#endif /* SERVIDOR_REMOTO_H_ */

