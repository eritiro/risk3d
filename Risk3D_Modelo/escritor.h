#ifndef ESCRITOR_H_
#define ESCRITOR_H_

#include <string>

using std::string;

class Escritor {
	public:
		virtual void escribir(string clave, string valor) = 0;
		virtual void escribir(string clave, int valor) = 0;
		virtual void escribir(string clave, bool valor) = 0;
		virtual void abrir_nodo(string clave) = 0;
		virtual void cerrar_nodo() = 0;
};

#endif /* ESCRITOR_H_ */
