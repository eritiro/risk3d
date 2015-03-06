#ifndef LECTOR_H_
#define LECTOR_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Nodo{
	public:
		virtual ~Nodo(){
		}
};

typedef vector<Nodo*> ContenedorNodos;
typedef ContenedorNodos::iterator IteradorNodos;

class Lector {
	public:
		virtual string leer_string(string clave) = 0;
		virtual int leer_int(string clave) = 0;
		virtual bool leer_bool(string clave) = 0;
		virtual void visitar_nodo(string clave) = 0;
		virtual void visitar_nodo(Nodo* nodo) = 0;
		virtual void salir_nodo() = 0;
		virtual ContenedorNodos& get_nodos(string clave) = 0; 
};

#endif /* LECTOR_H_ */
