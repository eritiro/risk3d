#ifndef TIPO_DE_ORDEN_H_
#define TIPO_DE_ORDEN_H_

#include <string>

using std::string;

class TipoDeOrden {
	private:
		string clave;
		TipoDeOrden(string clave);

	public:
		string get_clave();
		static operator==(const TipoDeOrden& un_tipo, const TipoDeOrden& otro_tipo);

		static TipoDeOrden comenzar_el_juego() { return TipoDeOrden("Comenzar Juego"); }
		static TipoDeOrden cancelar_el_juego() { return TipoDeOrden("Cancelar Juego"); }
		static TipoDeOrden agregar_jugador() { return TipoDeOrden("Agregar Jugador"); }
		static TipoDeOrden quitar_jugador() { return TipoDeOrden("Quitar Jugador"); }

		static TipoDeOrden atacar() { return TipoDeOrden("Atacar"); }
		static TipoDeOrden defender() {	return TipoDeOrden("Defender"); }
		static TipoDeOrden reagrupar_ejercitos() { return TipoDeOrden("Reagrupar Ejercitos"); }
		static TipoDeOrden reforzar_territorio() { return TipoDeOrden("Reforzar Territorio"); }
		static TipoDeOrden terminar_turno() { return TipoDeOrden("Terminar Turno"); }
		static TipoDeOrden chatear() { return TipoDeOrden("Chatear"); }
};

#endif /* TIPO_DE_ORDEN_H_ */
