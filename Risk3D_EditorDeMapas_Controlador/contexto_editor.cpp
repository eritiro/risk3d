#include "contexto_editor.h"

 
ContextoEditor::ContextoEditor() 
	: mapa_activo(false){
	mapa = 0;
}

ContextoEditor ContextoEditor::CrearContexto(){
	return ContextoEditor();
}

Mapa& ContextoEditor::get_mapa(){
	return *this->mapa;
}

void ContextoEditor::set_mapa(Mapa* mapa){
	if(this->mapa != mapa) 
		delete this->mapa;
	this->mapa = mapa;
}

bool ContextoEditor::hay_mapa_activo(){
	return this->mapa_activo;
}


void ContextoEditor::set_mapa_activo(bool value){
	this->mapa_activo = value;
}


void ContextoEditor::set_mapa_modificado(bool value){
	this->mapa_modificado = value;
}


bool ContextoEditor::fue_modificado_mapa(){
	return this->mapa_modificado;
}


void ContextoEditor::set_mapa_inicialmente_guardado(bool value){
	this->mapa_inicialmente_guardado = value;
}


bool ContextoEditor::fue_guardado_inicialmente_mapa(){
	return this->mapa_inicialmente_guardado;
}


void ContextoEditor::set_coordenada_actual(Coordenada coordenada){
	this->coordenada_actual = coordenada;
}


Coordenada ContextoEditor::get_coordenada_actual(){
	return this->coordenada_actual;
}


void ContextoEditor::set_territorio_actual(Territorio* territorio){
	this->territorio_actual = territorio;
}


Territorio* ContextoEditor::get_territorio_actual(){
	return this->territorio_actual;
}


void ContextoEditor::set_es_territorio_nuevo(bool value){
	this->es_territorio_nuevo = value;
}


bool ContextoEditor::get_es_territorio_nuevo(){
	return this->es_territorio_nuevo;
}


bool ContextoEditor::get_es_nuevo_requisito(){
	return this->es_nuevo_requisito;
}


void ContextoEditor::set_es_nuevo_requisito(bool value){
	this->es_nuevo_requisito = value;
}


void ContextoEditor::set_requisito_seleccionado(RequisitoDeOcupacion* requisito){
	this->requisito_seleccionado = requisito;
}


RequisitoDeOcupacion* ContextoEditor::get_requisito_seleccionado(){
	return this->requisito_seleccionado;
}