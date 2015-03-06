#ifndef CICLO_DE_VIDA_H_
#define CICLO_DE_VIDA_H_

#include <list>
#include "tranferible.h"
#include "macros.h"

using std::list;

typedef list<Tranferible*> ContenedorTranferibles;
typedef ContenedorTranferibles::iterator IteradorTranferibles;

class CicloDeVida {
	private:
		ContenedorTranferibles objetos_asociados;
	public:
		virtual ~CicloDeVida();
		void agregar_objeto_tranferible(Tranferible* objeto);
};

#endif /* CICLO_DE_VIDA_H_ */
