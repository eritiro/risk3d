#ifndef LECTOR_DE_XML_H_
#define LECTOR_DE_XML_H_

#include <stack>
#include "lector.h"
#include "documento_de_xml.h"
#include "utilidades_string.h"
#include "nodo_xml.h"

using std::stack;

typedef stack<NodoXml*> PilaNodosXml;

class LectorDeXml : public Lector {
	private:
		DocumentoDeXml* documento;
		PilaNodosXml nodos;
		LectorDeXml(DocumentoDeXml* documento);
		
	public:
		~LectorDeXml();
		string leer_string(string clave);
		int leer_int(string clave);
		bool leer_bool(string clave);

		void visitar_nodo(string clave);
		void visitar_nodo(Nodo* nodo);
		void salir_nodo();
		ContenedorNodos& get_nodos(string clave); 

		static LectorDeXml crear_lector_desde_archivo(string nombre_archivo);
		static LectorDeXml crear_lector_de_memoria(string texto);
};

#endif /* LECTOR_DE_XML_H_ */
