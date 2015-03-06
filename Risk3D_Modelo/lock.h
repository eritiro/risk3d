#ifndef LOCK_H_
#define LOCK_H_

#include "mutex.h"

class Lock{
	private:
		Mutex& mutex;

		//Constructor de copia y operador = privados para prevenir descuidos
		Lock(const Lock&);
		Lock& operator=(const Lock&);

	public:
		Lock(Mutex& mutex);
		~Lock();
};

#endif /* LOCK_H_ */
