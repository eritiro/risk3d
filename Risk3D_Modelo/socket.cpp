#include "socket.h"

Mutex Socket::mutex_instancias;
int Socket::instancias = 0;

// C++ no soporta constructores llamados en cadena.
void Socket::Construir(){
	// Entra en una seccion critica para modificar la cantidad de instancias e iniciar el funcionamiento
	// de los socket.
	Lock lock(mutex_instancias);
	if(instancias == 0){
		WSADATA WsaData;
		WSAStartup(MAKEWORD(2, 2), &WsaData);
	}
	instancias++;
}

Socket::Socket()
	: descriptor(SOCKET_CERRADO) {
	this->Construir();
}

Socket::Socket(int descriptor)
	: descriptor(descriptor) {	
	this->Construir();
}

Socket::~Socket(){
	this->desconectar();
	// Se asegura de entrar a una seccion critica antes de modificar las cantidad de instancias
	// y hacer un clean-up cuando estas llegan a cero.
	{ 
		Lock lock(mutex_instancias);
		instancias--;
		if(instancias == 0)
			WSACleanup();
	}
}

void Socket::conectar(const string &host , Port puerto){
	struct hostent* host2 = gethostbyname(host.c_str());
	if (host2 == NULL)
		throw ExcepcionDeSocket("No se puede resolver la dirección de ip.");

	descriptor = crear_descriptor_socket();
	SOCKADDR_IN direccion;
	memset (&direccion, 0, sizeof (direccion));
	direccion.sin_family = AF_INET;
	direccion.sin_port = htons(puerto);
	direccion.sin_addr.s_addr = ((struct in_addr *)(host2->h_addr))->s_addr;
	int resultado = connect(descriptor , (SOCKADDR*)&direccion , sizeof(direccion));
	if(resultado != 0)
		throw ExcepcionDeSocket("No se puede conectar establecer la conexión.");
}

void Socket::conectar(Port puerto, int cantidad_maxima_de_conexiones_pendientes){
	descriptor = crear_descriptor_socket();

	SOCKADDR_IN direccion;
	memset(&direccion, 0, sizeof (direccion));
	direccion.sin_family = AF_INET;
	direccion.sin_port = htons(puerto);
	if(bind(descriptor , (SOCKADDR*)&direccion , sizeof(direccion)) == SOCKET_CERRADO)	
		throw ExcepcionDeSocket("No se puede escuchar el puerto socket.");

	listen(descriptor, cantidad_maxima_de_conexiones_pendientes);
}

void Socket::enviar(const string &datos){
	// pre-condiciones:
	if (!esta_conectado())
		throw ExcepcionSocketInvalido();
		
	int total_caracteres_escritos = 0;
	int total_caracteres_a_escribir = (int)datos.length();
	while(total_caracteres_escritos < total_caracteres_a_escribir){
		int caracteres_escritos = send(descriptor, datos.c_str() + total_caracteres_escritos, total_caracteres_a_escribir - total_caracteres_escritos, 0);

		if ((caracteres_escritos == 0) || (caracteres_escritos == SOCKET_CERRADO))
			throw ExcepcionSocketCerrado();

		total_caracteres_escritos +=  caracteres_escritos;
	}	
}

string Socket::recibir(int medida_esperada){
	// pre-condiciones:
	if (!esta_conectado())
		throw ExcepcionSocketInvalido();

	string buffer;
	buffer.assign(medida_esperada,' ');
	
	int total_caracteres_leidos = 0;
	while(total_caracteres_leidos < medida_esperada){
		int caraceteres_leidos = recv(descriptor , (char*)(buffer.c_str() + total_caracteres_leidos), medida_esperada - total_caracteres_leidos,0);
		
		if ((caraceteres_leidos == 0) || (caraceteres_leidos == SOCKET_CERRADO))
			throw ExcepcionSocketCerrado();

		total_caracteres_leidos +=  caraceteres_leidos;
	}

	return buffer;
}

Socket* Socket::aceptar(){
	// pre-condiciones:
	if (!esta_conectado())
		throw ExcepcionSocketInvalido();
	
	int nuevo_descriptor = (int)accept(descriptor, NULL, NULL);

	if (nuevo_descriptor != SOCKET_CERRADO)
		return new Socket(nuevo_descriptor);
	else
		return NULL;
}

bool Socket::esta_conectado() const{
	return descriptor != SOCKET_CERRADO;
}

void Socket::desconectar(){
	Lock lock(mutex_conexion);
	if(esta_conectado())
	{
		closesocket(descriptor);
		descriptor = SOCKET_CERRADO;
	}
}

int Socket::crear_descriptor_socket(){
	int descriptor = (int)socket(AF_INET ,SOCK_STREAM , 0);
	if (descriptor != SOCKET_CERRADO)
		return descriptor;
	else
		throw ExcepcionDeSocket("No se puede crear el socket.");		
}