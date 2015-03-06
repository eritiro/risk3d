#include "lector_de_xml.h"

LectorDeXml::LectorDeXml(DocumentoDeXml* documento) 
	: documento(documento){
}

LectorDeXml::~LectorDeXml(){
	delete this->documento;
}

LectorDeXml LectorDeXml::crear_lector_de_memoria(string texto){
	DocumentoDeXml* documento = DocumentoDeXml::crear_documento_desde_memoria(texto);
	return LectorDeXml(documento);
}

LectorDeXml LectorDeXml::crear_lector_desde_archivo(string nombre_archivo){
	DocumentoDeXml* documento = DocumentoDeXml::crear_documento_desde_archivo(nombre_archivo);
	return LectorDeXml(documento);
}

string LectorDeXml::leer_string(string clave){
	return documento->obtener_atributo(nodos.top()->nodo_verdadero, clave);
}

int LectorDeXml::leer_int(string clave){
	return UtilidadesString::string_a_int(this->leer_string(clave));
}

bool LectorDeXml::leer_bool(string clave){
	return this->leer_int(clave) == 1;
}

void LectorDeXml::visitar_nodo(string clave){
	NodoXml* nodo = new NodoXml;
	if(nodos.empty())
	{
		nodo->ruta = "//" + clave;
	}
	else
	{
		nodo->ruta = nodos.top()->ruta + "/" + clave;
	}
	nodos.push(nodo);
	nodo->nodo_verdadero = documento->obtener_nodo(nodos.top()->ruta);
}

void LectorDeXml::visitar_nodo(Nodo* nodo){
	nodos.push(dynamic_cast<NodoXml*>(nodo));
}

void LectorDeXml::salir_nodo(){
	delete nodos.top();
	nodos.pop();
}

ContenedorNodos& LectorDeXml::get_nodos(string clave){
	if(nodos.top()->hijos == 0){
		nodos.top()->hijos = new ContenedorNodos();
		long length;
		IXMLDOMNodeList* lista = documento->obtener_nodos(nodos.top()->ruta + "/" + clave);

		lista->get_length(&length);
		for (int i=0; i<length; i++) {
			NodoXml* nodo = new NodoXml();
			lista->get_item(i, &(nodo->nodo_verdadero));
			nodo->ruta = nodos.top()->ruta + "/" + clave + "[" + UtilidadesString::int_a_string(i) + "]";
			nodos.top()->hijos->push_back(nodo);
		}
		
	}
	
	return *nodos.top()->hijos;
}
