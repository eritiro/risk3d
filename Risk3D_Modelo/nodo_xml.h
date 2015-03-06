#ifndef NODO_XML_H_
#define NODO_XML_H_

#include "lector.h"

class NodoXml : public Nodo {
	public:
		IXMLDOMNode * nodo_verdadero;
		string ruta;
		ContenedorNodos* hijos;

		NodoXml(){
			this->hijos = 0;
		}
		~NodoXml(){
			this->nodo_verdadero->Release();
			if(this->hijos != 0)
				delete this->hijos;
		}
};

#endif /* NODO_XML_H_ */
