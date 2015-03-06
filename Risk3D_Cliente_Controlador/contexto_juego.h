#ifndef CONTEXTO_JUEGO_H_
#define CONTEXTO_JUEGO_H_

#include <string>
#include "hilo_ejecucion.h"
#include "servidor.h"

using std::string;

class ContextoJuego {
	private:
		ContextoJuego();

		bool es_creador_del_juego;
		string host;
		HiloEjecucion* hilo_servidor;
		int id_imperio;
		Servidor* servidor;

		//Lo defino como un objeto no copiable
		ContextoJuego(ContextoJuego const &);
		ContextoJuego& operator= (const ContextoJuego&);
	public:
		//Este metodo debe ser invocado para crear un nuevo contexto.
		static ContextoJuego CrearContexto();

		//Aca va todo lo que necesito que compartan mis controladores del juego:
		bool get_es_creador_del_juego();
		void set_es_creador_del_juego(bool valor);

		int get_id_imperio();
		void set_id_imperio(int valor);

		string get_host();
		void set_host(string valor);

		HiloEjecucion* get_hilo_servidor();
		void set_hilo_servidor(HiloEjecucion* valor);

		Servidor* get_servidor();
		void set_servidor(Servidor* valor);
};

#endif /* CONTEXTO_JUEGO_H_ */
