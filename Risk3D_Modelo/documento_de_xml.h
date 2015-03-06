#ifndef DOCUMENTO_DE_XML_H_
#define DOCUMENTO_DE_XML_H_

#include <string>
#include <objbase.h>
#include <msxml2.h>
#include "excepcion_de_xml.h"

using std::string;

typedef IXMLDOMElement NODO;

class DocumentoDeXml {
	private:
		IXMLDOMDocument* pxmldoc;

		static VARIANT crear_variant_string(string s);
		static OLECHAR* DocumentoDeXml::convertir_string_a_olechar(string s);
		static bool inicializado;
		static void DocumentoDeXml::agregar_hijo(IXMLDOMNode* padre, IXMLDOMNode* hijo);
		string convertir_olechar_a_string(OLECHAR* c);
	protected:
		DocumentoDeXml();

	public:
		~DocumentoDeXml();

		void tabular_nodo(IXMLDOMNode *nodo, int subnivel);
		IXMLDOMElement* crear_nodo(string nombre, IXMLDOMNode* padre);
		IXMLDOMElement* crear_nodo_raiz(string nombre);
		void agregar_atributo(NODO* nodo, string clave, string valor);
		IXMLDOMNode* obtener_nodo(string path);
		string obtener_atributo(IXMLDOMNode* nodo, string clave);
		IXMLDOMNodeList* obtener_nodos(string path);
		string get_xml();

		static DocumentoDeXml* crear_nuevo_documento();
		static DocumentoDeXml* crear_documento_desde_memoria(string texto);
		static DocumentoDeXml* crear_documento_desde_archivo(string nombre_archivo);

		void guardar(string nombre_archivo);
};

#endif /* DOCUMENTO_DE_XML_H_ */
