#include "oyente_de_peticiones.h"
#include "jugador_remoto.h"
#include "proveedor_de_ordenes_remotas.h"

static Log log("OyenteDePeticiones");

OyenteDePeticiones::OyenteDePeticiones(ProveedorDeOrdenesRemotas* proveedor, int puerto_escucha, Mapa* mapa)
	: continuar(true), proveedor(proveedor), mapa(mapa) {
	socket.conectar(puerto_escucha, CANTIDAD_MAXIMA_JUGADORES);
}

OyenteDePeticiones::~OyenteDePeticiones(){
	continuar = false;
	socket.desconectar();
	this->unir();
}

void OyenteDePeticiones::ejecutar(){

	log.info("Iniciada la escucha de nuevas conexiones.");
	try{
		while(continuar){
			Socket* nuevo_socket = socket.aceptar();
			if(nuevo_socket!=0){
				proveedor->agregar_jugador(new JugadorRemoto(nuevo_socket, proveedor, mapa));
			}
		}
	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida"));
	}
	log.info("Finalizada la escucha de nuevas conexiones.");
}
