#ifndef SERIALIZADOR_MENSAJE_H_
#define SERIALIZADOR_MENSAJE_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el map es un template
// "asi de grande".
#pragma warning(disable:4786)
#include <map>
#include "escritor.h"
#include "lector.h"
#include "excepcion_de_serializacion.h"
#include "log.h"
#include "serializador_mensaje_estandar.h"

#include "evento_juego_iniciado.h"
#include "evento_juego_cancelado.h"
#include "evento_comienzo_turno.h"
#include "serializador_defensa_requerida.h"
#include "serializador_evento_jugador_agregado.h"
#include "serializador_evento_juego_terminado.h"
#include "serializador_evento_batalla_producida.h"
#include "serializador_actualizacion.h"
#include "serializador_mensaje_de_error.h"
#include "serializador_mensaje_de_sistema.h"
#include "serializador_mensaje_de_chat.h"
#include "serializador_mensaje_objetivo_secreto.h"

using std::map;

typedef map<string, SerializadorMensajeEspecifico*> TablaSerializadoresMensaje;
typedef TablaSerializadoresMensaje::iterator IteradorSerializadoresMensaje;

class SerializadorMensaje {
	private:
		TablaSerializadoresMensaje serializadores;
		void registrar(TipoDeMensaje& tipo, SerializadorMensajeEspecifico* serializador);
		void lanzar_excepcion_serializador_especifico(string tipo);
	public:
		SerializadorMensaje();
		~SerializadorMensaje();
		void serializar(Escritor& escritor, Mensaje& mensaje);
		Mensaje* deserializar(Lector& lector, InfoJuego& info);
};

#endif /* SERIALIZADOR_MENSAJE_H_ */
