#ifndef THREAD_H_
#define THREAD_H_

#include <windows.h>
#include "excepcion_de_concurrencia.h"

class Thread{
	private:
		HANDLE handler;
		DWORD tid;
		bool esta_corriendo;
		static DWORD WINAPI ejecutar_thread(void* arg);

		//Constructor de copia y operador = privados para prevenir descuidos
		Thread(const Thread&);
		Thread& operator=(const Thread&);

	protected:
		virtual void ejecutar() = 0;

	public:
		Thread();
		virtual ~Thread();
		
		// Lanza el thread
		void comenzar();
		// Espera a que el thread termine
		void unir();
		// Frena al hilo a la fuerza
		void frenar();
		static void dormir(unsigned long milisegundos);
};

#endif /* THREAD_H_ */
