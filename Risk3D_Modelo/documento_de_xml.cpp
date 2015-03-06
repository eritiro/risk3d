#include "documento_de_xml.h"

bool DocumentoDeXml::inicializado = false;

DocumentoDeXml::DocumentoDeXml()
{
	//if(!inicializado){
		CoInitialize(NULL);
		inicializado = true;
	//}

	pxmldoc = NULL;

	HRESULT resultado;
    
    resultado = CoCreateInstance(__uuidof(DOMDocument30), NULL, CLSCTX_INPROC_SERVER, __uuidof(IXMLDOMDocument), (void**)&pxmldoc);
	if(FAILED(resultado)) throw ExcepcionDeXml("No se puede crear el documento de Xml.");
	pxmldoc->put_async(VARIANT_FALSE);
    pxmldoc->put_validateOnParse(VARIANT_FALSE);
    pxmldoc->put_resolveExternals(VARIANT_FALSE);
}

string DocumentoDeXml::get_xml(){
	BSTR bstr = NULL;
	pxmldoc->get_xml(&bstr);
	string resultado_feliz = convertir_olechar_a_string(bstr);
	if (bstr) SysFreeString(bstr);
	return resultado_feliz;
}

DocumentoDeXml::~DocumentoDeXml(){
	this->pxmldoc->Release();
}

DocumentoDeXml* DocumentoDeXml::crear_nuevo_documento(){
	DocumentoDeXml* doc = new DocumentoDeXml();
	// Variables a usar *
    BSTR xml = SysAllocString(L"xml");
    BSTR version = SysAllocString(L"version='1.0'");
	IXMLDOMProcessingInstruction* pi= NULL;
	// ******************

    doc->pxmldoc->createProcessingInstruction(xml, version, &pi);
    agregar_hijo(doc->pxmldoc, pi);

	// Las libero *******
	if (xml) SysFreeString(xml);
	if (version) SysFreeString(version);
	if (pi) pi->Release();
	// ******************
	return doc;
}

DocumentoDeXml* DocumentoDeXml::crear_documento_desde_archivo(string nombre_archivo){
	DocumentoDeXml* documento = new DocumentoDeXml();

    VARIANT var = crear_variant_string(nombre_archivo); 
	VARIANT_BOOL status;
	HRESULT resultado = documento->pxmldoc->load(var, &status);
    VariantClear(&var);
    if (FAILED(resultado) || status!=VARIANT_TRUE) throw ExcepcionDeXml("No se puede leer el documento de Xml.");
	return documento;
}

DocumentoDeXml* DocumentoDeXml::crear_documento_desde_memoria(string texto){
	DocumentoDeXml* documento = new DocumentoDeXml();

	VARIANT_BOOL status;

	//BSTR bstr =  SysAllocString(L"<r>\n<t>top</t>\n<b>bottom</b>\n</r>");
	//BSTR bstr =  SysAllocString(L"<orden tipo=\"Agregar Jugador\" nombre=\"Juan Carlos\" color=\"2\"></orden>");
    
    BSTR bstr = SysAllocString(convertir_string_a_olechar(texto)); 
	HRESULT resultado = documento->pxmldoc->loadXML(bstr, &status);
	SysFreeString(bstr);
    if (FAILED(resultado) || status!=VARIANT_TRUE) throw ExcepcionDeXml("No se puede leer el documento de Xml.");
	return documento;
}

void DocumentoDeXml::guardar(string nombre_archivo){
    VARIANT var = crear_variant_string(nombre_archivo);
    this->pxmldoc->save(var);
	VariantClear(&var);
}


OLECHAR* DocumentoDeXml::convertir_string_a_olechar(string s)
{
	OLECHAR* p = (OLECHAR*)malloc(s.size() * 2 + 2);
	const char* c = s.c_str();
	int i = 0;
	while(c[i])
	{
		p[i] = c[i];
		i++;
	}
	p[i] = 0;
	return p;

}

string DocumentoDeXml::convertir_olechar_a_string(OLECHAR* c){
	string s;
	if(c==0) return "";
	int i = 0;
	while(c[i])
	{
		s = s + (char)c[i];
		i++;
	}
	return s;
}

VARIANT DocumentoDeXml::crear_variant_string(string s)
{
    VARIANT var;
    VariantInit(&var);
    V_BSTR(&var) = SysAllocString(convertir_string_a_olechar(s));
    V_VT(&var) = VT_BSTR;
    return var;
}

void DocumentoDeXml::tabular_nodo(IXMLDOMNode *nodo, int subnivel)
{
    IXMLDOMText *pws=NULL;
    IXMLDOMNode *pBuf=NULL;


	string s = "\n";
	for(int i = 0; i < subnivel; i++)
		s = s + "\t";

	BSTR tabulacion = convertir_string_a_olechar(s); //"\n" + string("\t", subnivel));
    this->pxmldoc->createTextNode(tabulacion, &pws);
    nodo->appendChild(pws, &pBuf);
    if (pws) pws->Release();
    if (pBuf) pBuf->Release();
}

void DocumentoDeXml::agregar_hijo(IXMLDOMNode* padre, IXMLDOMNode* hijo)
{
    IXMLDOMNode *nodo_raro = NULL;
    padre->appendChild(hijo, &nodo_raro);
    if (nodo_raro) nodo_raro->Release();
}

IXMLDOMElement* DocumentoDeXml::crear_nodo(string nombre, IXMLDOMNode* padre){
	IXMLDOMElement* nodo = 0;
    BSTR bstr = SysAllocString(convertir_string_a_olechar(nombre));
    this->pxmldoc->createElement(bstr, &nodo);
    SysFreeString(bstr);
	agregar_hijo(padre, nodo);
	return nodo;
}

IXMLDOMElement* DocumentoDeXml::crear_nodo_raiz(string nombre){
	return this->crear_nodo(nombre, this->pxmldoc);
}

void DocumentoDeXml::agregar_atributo(IXMLDOMElement* nodo, string clave, string valor){
	IXMLDOMAttribute* pa = NULL;
	IXMLDOMAttribute* pa1 = NULL;
    BSTR bstr = SysAllocString(convertir_string_a_olechar(clave));
    VARIANT var = crear_variant_string(valor);
    
	this->pxmldoc->createAttribute(bstr,&pa);
    pa->put_value(var);
    nodo->setAttributeNode(pa, &pa1);

	SysFreeString(bstr);
    if (pa1) pa1->Release();
    pa->Release();
    VariantClear(&var);
}


IXMLDOMNode* DocumentoDeXml::obtener_nodo(string path){

    BSTR bstr = SysAllocString(convertir_string_a_olechar(path)); //L"//stock[1]/*");
	IXMLDOMNode* nodo = 0;
    this->pxmldoc->selectSingleNode(bstr, &nodo);

    if (!nodo) throw ExcepcionDeXml("No se puede encontrar el nodo " + path);
    
	SysFreeString(bstr);

	return nodo;
    //pNode->get_nodeName(&bstr)
    //pNode->get_xml(&bstr)
}

IXMLDOMNodeList* DocumentoDeXml::obtener_nodos(string path){

    BSTR bstr = SysAllocString(convertir_string_a_olechar(path)); //L"//stock[1]/*");
	IXMLDOMNodeList* lista = 0;
    this->pxmldoc->selectNodes(bstr, &lista);

    if (!lista) throw ExcepcionDeXml("No se puede encontrar la lista de nodos " + path);
    
	SysFreeString(bstr);

	return lista;
    //pNode->get_nodeName(&bstr)
    //pNode->get_xml(&bstr)
}


string DocumentoDeXml::obtener_atributo(IXMLDOMNode* nodo, string clave){
	IXMLDOMNamedNodeMap* attributeMap = 0;
	BSTR nombre = SysAllocString(convertir_string_a_olechar(clave));
	IXMLDOMNode* namedItem = 0;
	VARIANT resultado;
	nodo->get_attributes(&attributeMap);
	attributeMap->getNamedItem(nombre, &namedItem);

	//nodo->get_nodeName(&nombre);
	//string resultado_bonito = convertir_olechar_a_string(nombre);
	try{
		namedItem->get_nodeValue(&resultado);
	}
	catch(...){
		throw ExcepcionDeXml("No se puede leer el atributo \"" + clave + "\"");
	}
	string resultado_bonito = convertir_olechar_a_string(V_BSTR(&resultado));
	
	if (attributeMap) attributeMap->Release();
	SysFreeString(nombre);
	if (namedItem) namedItem->Release();
	VariantClear(&resultado);

	return resultado_bonito;
}
