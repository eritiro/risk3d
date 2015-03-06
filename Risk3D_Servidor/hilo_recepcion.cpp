#include "hilo_recepcion.h"
#include "proveedor_de_ordenes_remotas.h"

static Log log("HiloRecepcion");

HiloRecepcion::HiloRecepcion(Socket* socket, ProveedorDeOrdenesRemotas* proveedor, JugadorRemoto* jugador)
	: socket(socket), proveedor(proveedor), jugador(jugador){
}

void HiloRecepcion::ejecutar(){
	log.info("Se inició el hilo de recepción de datos de cliente.");
	try{
		while(socket->esta_conectado()){
			Thread::dormir(MILISEGUNDOS_POOLEO_RECEPCION_ORDEN);
			string buffer = socket->recibir(DIGITOS_MEDIDA_DEL_PAQUETE);
			int medida_mensaje = UtilidadesString::string_a_int(buffer);
			buffer = socket->recibir(medida_mensaje);
			proveedor->agregar_orden(buffer, jugador);
		}
	}
	catch(ExcepcionSocketCerrado){
		log.info("Se interrumpio la conexion con el socket cliente.");

		EscritorDeXml escritor;
		Orden* orden = FabricaDeOrdenes::crear_orden_quitar_jugador();
		this->serializador.serializar(escritor, *orden);
		string orden_serializada = escritor.get_xml();
		proveedor->agregar_orden(orden_serializada, jugador);
		delete orden;

	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida."));
	}
	log.info("Finalizó el hilo de recepción de datos de cliente.");
	socket->desconectar();
}
