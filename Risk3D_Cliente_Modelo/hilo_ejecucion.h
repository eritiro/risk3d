#ifndef HILO_EJECUCION_H_
#define HILO_EJECUCION_H_

#include "thread.h"

class HiloEjecucion : public Thread {
	private:
		string comando;
	protected:
		void ejecutar();
	public:
		HiloEjecucion(string comando);
};


#endif /* HILO_EJECUCION_H_ */
