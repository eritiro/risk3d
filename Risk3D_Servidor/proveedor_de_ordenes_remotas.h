#ifndef PROVEEDOR_DE_ORDENES_REMOTAS_H_
#define PROVEEDOR_DE_ORDENES_REMOTAS_H_

#pragma warning(disable:4786)
#include <queue>
#include <utility>
#include "jugador_remoto.h"
#include "proveedor_de_ordenes.h"
#include "log.h"
#include "lock.h"
#include "constantes.h"
#include "thread.h"
#include "lector_de_xml.h"
#include "serializador_orden.h"
#include "oyente_de_peticiones.h"
#include "log.h"

using std::queue;
using std::pair;

typedef list<JugadorRemoto*> ContenedorJugadoresRemotos;
typedef ContenedorJugadoresRemotos::iterator IteradorJugadoresRemotos;
typedef pair<JugadorRemoto*, string> OrdenSerializada;

class ProveedorDeOrdenesRemotas : public ProveedorDeOrdenes {
	private:
		Mutex mutex;
		ContenedorJugadoresRemotos jugadores;
		queue<OrdenSerializada> ordenes;
		bool hay_ordenes_pendientes();
		SerializadorOrden serializador_orden;
		OyenteDePeticiones* oyente;
		OrdenSerializada desencolar_orden();
	public:
		ProveedorDeOrdenesRemotas(int puerto_para_nuevas_conexiones, Mapa* mapa);
		~ProveedorDeOrdenesRemotas();
		OrdenExtendida* get_orden(InfoJuego& info);
		void agregar_orden(string orden, JugadorRemoto* jugador);
		void agregar_jugador(JugadorRemoto* jugador);
};

#endif /* PROVEEDOR_DE_ORDENES_REMOTAS_H_ */
