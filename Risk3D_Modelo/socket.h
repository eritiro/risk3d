#ifndef SOCKET_H_
#define SOCKET_H_

//#pragma comment(lib,"ws2_32.lib")

#include <winsock.h>
#include <string>
#include "excepcion_de_socket.h"
#include "excepcion_socket_cerrado.h"
#include "excepcion_socket_invalido.h"
#include "lock.h"

using std::string;

typedef unsigned short Port;

#define SOCKET_CERRADO -1

class Socket{
	private:
		static Mutex mutex_instancias;
		static int instancias;

		int descriptor;
		Mutex mutex_conexion;
		
		Socket(int descriptor);
		int crear_descriptor_socket();
		// Para suplir la falta de constructores encadenados:
		void Construir();

		//Constructor de copia y operador = privados para prevenir descuidos
		Socket(const Socket &a);
		Socket &operator=(const Socket &a);

	public:
		Socket();
		virtual ~Socket();

		void conectar(const string &host, Port port);
		void conectar(Port puerto, int cantidad_maxima_de_conexiones_pendientes);
		void desconectar();

		void enviar(const string &buf);
		string recibir(int medida_esperada);
		Socket* aceptar();
		bool esta_conectado() const;
};

#endif /* SOCKET_H_ */
