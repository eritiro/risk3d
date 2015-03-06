#ifndef ESCRITOR_DE_XML_H_
#define ESCRITOR_DE_XML_H_

#include <stack>
#include "escritor.h"
#include "utilidades_string.h"
#include "documento_de_xml.h"

using std::stack;

typedef stack<NODO*> PilaNodosMsxml;

class EscritorDeXml : public Escritor {
	private:
		DocumentoDeXml* documento;
		PilaNodosMsxml nodos;
	public:
		EscritorDeXml();
		~EscritorDeXml();
		void escribir(string clave, string valor);
		void escribir(string clave, int valor);
		void escribir(string clave, bool valor);

		void abrir_nodo(string clave);
		void cerrar_nodo();
		void guardar_archivo(string nombre_archivo);
		string get_xml();
};

#endif /* ESCRITOR_DE_XML_H_ */
