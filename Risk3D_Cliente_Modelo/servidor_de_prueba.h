#ifndef SERVIDOR_DE_PRUEBA_H_
#define SERVIDOR_DE_PRUEBA_H_

#include "servidor.h"
#include "lector_de_xml.h"
#include "serializador_mapa.h"
#include "fabrica_de_mensajes.h"

class ServidorDePrueba : public Servidor{
	private:
		Mapa* mapa;
		InfoJuego* info;
		bool info_enviada;
	public:
		ServidorDePrueba(string ruta_mapa);
		~ServidorDePrueba();

		void enviar(Orden* orden);
		Mensaje* get_mensaje();
		
		InfoJuego* get_info();

		bool get_juego_terminado();
};


#endif /* SERVIDOR_DE_PRUEBA_H_ */
