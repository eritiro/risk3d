#ifndef PROVEEDOR_DE_ORDENES_H_
#define PROVEEDOR_DE_ORDENES_H_

#include "orden_extendida.h"
#include "info_juego.h"

class ProveedorDeOrdenes {
	public:
		//Genera una orden para el juego.
		//InfoJuego& info: la informacion necesaria para establecer las relaciones de las ordenes.
		virtual OrdenExtendida* get_orden(InfoJuego& info) = 0;
		virtual ~ProveedorDeOrdenes(){
		}
};

#endif /* PROVEEDOR_DE_ORDENES_H_ */
