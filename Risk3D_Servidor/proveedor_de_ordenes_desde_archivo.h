#ifndef PROVEEDOR_DE_ORDENES_DESDE_ARCHIVO_H_
#define PROVEEDOR_DE_ORDENES_DESDE_ARCHIVO_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el map es un template
// "asi de grande".
#pragma warning(disable:4786)
#include <map>

#include <iostream>
#include <fstream>
#include "proveedor_de_ordenes.h"
#include "log.h"
#include "jugador_de_prueba.h"
#include "utilidades_string.h"
#include "serializador_orden.h"
#include "lector_de_xml.h"

using std::ifstream;
using std::string;
using std::map;

typedef map<int, Jugador*> TablaJugadores;
typedef TablaJugadores::iterator IteradorTablaJugadores;

class ProveedorDeOrdenesDesdeArchivo : public ProveedorDeOrdenes {
	private:
		ifstream archivo;
		TablaJugadores jugadores;
		SerializadorOrden serializador;
	public:
		ProveedorDeOrdenesDesdeArchivo(string nombre_archivo);
		~ProveedorDeOrdenesDesdeArchivo();
		OrdenExtendida* get_orden(InfoJuego& info);
};

#endif /* PROVEEDOR_DE_ORDENES_DESDE_ARCHIVO_H_ */
