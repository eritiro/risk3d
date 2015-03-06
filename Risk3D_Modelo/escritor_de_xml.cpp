#include "escritor_de_xml.h"

EscritorDeXml::EscritorDeXml() : documento(DocumentoDeXml::crear_nuevo_documento()){
}

EscritorDeXml::~EscritorDeXml(){
	delete this->documento;
}

void EscritorDeXml::escribir(string clave, string valor){
	documento->agregar_atributo(nodos.top(), clave, valor);
}

void EscritorDeXml::escribir(string clave, int valor){
	this->escribir(clave, UtilidadesString::int_a_string(valor));
}

void EscritorDeXml::escribir(string clave, bool valor){
	this->escribir(clave, valor ? 1 : 0);
}

void EscritorDeXml::abrir_nodo(string clave){
	NODO* nuevo_nodo;
	if(nodos.empty()){
		nuevo_nodo = documento->crear_nodo_raiz(clave);
	}
	else{
		documento->tabular_nodo(nodos.top(), nodos.size());
		nuevo_nodo = documento->crear_nodo(clave, nodos.top());
	}
	nodos.push(nuevo_nodo);
}

void EscritorDeXml::cerrar_nodo(){
	documento->tabular_nodo(nodos.top(), nodos.size() -1);
	nodos.top()->Release();
	nodos.pop();
}

void EscritorDeXml::guardar_archivo(string nombre_archivo){
	documento->guardar(nombre_archivo);
}

string EscritorDeXml::get_xml(){
	return documento->get_xml();
}