#ifndef OYENTE_DE_PETICIONES_H_
#define OYENTE_DE_PETICIONES_H_

#include "socket.h"
#include "thread.h"
#include "constantes.h"
#include "log.h"
#include "mapa.h"

class ProveedorDeOrdenesRemotas;

class OyenteDePeticiones : public Thread {
	private:
		Socket socket;
		bool continuar;
		ProveedorDeOrdenesRemotas* proveedor;
		Mapa* mapa;
	protected:
		void ejecutar();
	
	public:
		OyenteDePeticiones(ProveedorDeOrdenesRemotas* proveedor, int puerto_escucha, Mapa* mapa);
		~OyenteDePeticiones();
};

#endif /* OYENTE_DE_PETICIONES_H_ */
