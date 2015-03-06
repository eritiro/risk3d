#ifndef MUTEX_H_
#define MUTEX_H_

#include <windows.h>

class Mutex{
	private:
		CRITICAL_SECTION cs;

		//Constructor de copia y operador = privados para prevenir descuidos
		Mutex(const Mutex&);
		Mutex& operator=(const Mutex&);

	public:
		Mutex();
		~Mutex();
		void bloquear();
		void desbloquear();
};

#endif /* MUTEX_H_ */
