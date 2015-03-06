#ifndef SERIALIZADOR_INFO_JUEGO_H_
#define SERIALIZADOR_INFO_JUEGO_H_

#include "info_juego.h"
#include "escritor.h"
#include "lector.h"

class SerializadorInfoJuego {
	private:
		void serializar_imperio(Escritor& escritor, Imperio& imperio);
		void serializar_tropa(Escritor& escritor, Tropa& tropa);

		void deserializar_imperio(Lector& lector, Nodo* nodo, InfoJuego* info);
		void deserializar_tropa(Lector& lector, Nodo* nodo, InfoJuego* info, Imperio* imperio);
	public:
		void serializar(Escritor& escritor, InfoJuego& info);
		InfoJuego* deserializar(Lector& lector, Mapa& mapa);
};

#endif /* SERIALIZADOR_INFO_JUEGO_H_ */
