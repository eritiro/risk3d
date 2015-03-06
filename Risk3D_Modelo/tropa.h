#ifndef TROPA_H_
#define TROPA_H_

#include "territorio.h"

class Imperio;

class Tropa {
	private:
		Territorio* territorio;
		Imperio* imperio;
		int ejercitos;
	public:
		Tropa(Imperio* imperio, Territorio* territorio, int ejercitos);

		//getter y setters:
		Territorio* get_territorio();
		Imperio* get_imperio();
		int get_ejercitos();
		void set_ejercitos(int valor);
		void agregar_ejercitos(int valor);
};


#endif /* TROPA_H_ */
