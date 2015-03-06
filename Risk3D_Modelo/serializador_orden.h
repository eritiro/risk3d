#ifndef SERIALIZADOR_ORDEN_H_
#define SERIALIZADOR_ORDEN_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el map es un template
// "asi de grande".
#pragma warning(disable:4786)
#include <map>
#include "escritor.h"
#include "lector.h"
#include "excepcion_de_serializacion.h"
#include "serializador_orden_estandar.h"

#include "orden_quitar_jugador.h"
#include "orden_comenzar_juego.h"
#include "orden_cancelar_juego.h"
#include "orden_terminar_turno.h"
#include "serializador_orden_agregar_jugador.h"
#include "serializador_orden_atacar.h"
#include "serializador_orden_defender.h"
#include "serializador_orden_reagrupar_ejercitos.h"
#include "serializador_orden_reforzar_territorio.h"
#include "serializador_orden_chatear.h"

using std::map;

typedef map<string, SerializadorOrdenEspecifica*> TablaSerializadoresOrden;
typedef TablaSerializadoresOrden::iterator IteradorSerializadoresOrden;

class SerializadorOrden {
	private:
		TablaSerializadoresOrden serializadores;
		void registrar(TipoDeOrden& tipo, SerializadorOrdenEspecifica* serializador);
	public:
		SerializadorOrden();
		~SerializadorOrden();
		void serializar(Escritor& escritor, Orden& orden);
		Orden* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_ORDEN_H_ */
