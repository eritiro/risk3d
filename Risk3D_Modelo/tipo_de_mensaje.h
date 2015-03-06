#ifndef TIPO_DE_MENSAJE_H_
#define TIPO_DE_MENSAJE_H_

#include <string>

using std::string;

class TipoDeMensaje {
	private:
		string clave;
		TipoDeMensaje(string clave);

	public:
		string get_clave();

		static TipoDeMensaje actualizacion() { return TipoDeMensaje("Actualizacion"); }
		static TipoDeMensaje comienzo_turno() { return TipoDeMensaje("Comienzo Turno"); }
		static TipoDeMensaje juego_iniciado() { return TipoDeMensaje("Juego Iniciado"); }
		static TipoDeMensaje juego_terminado() { return TipoDeMensaje("Juego Terminado"); }
		static TipoDeMensaje juego_cancelado() { return TipoDeMensaje("Juego Cancelado"); }
		static TipoDeMensaje jugador_agregado() { return TipoDeMensaje("Jugador Agregado"); }
		static TipoDeMensaje mensaje_de_error() { return TipoDeMensaje("Error"); }
		static TipoDeMensaje mensaje_de_sistema() { return TipoDeMensaje("Mensaje De Sistema"); }
		static TipoDeMensaje mensaje_de_chat() { return TipoDeMensaje("Mensaje De Chat"); }
		static TipoDeMensaje defensa_requerida() { return TipoDeMensaje("Defensa Requerida"); }
		static TipoDeMensaje batalla_producida() { return TipoDeMensaje("Batalla Producida"); }
		static TipoDeMensaje mensaje_objetivo_secreto() { return TipoDeMensaje("Objetivo Secreto"); }
};

#endif /* TIPO_DE_MENSAJE_H_ */
