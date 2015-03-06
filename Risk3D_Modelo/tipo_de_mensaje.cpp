#include "tipo_de_mensaje.h"

TipoDeMensaje::TipoDeMensaje(string clave) : clave(clave){
}

string TipoDeMensaje::get_clave(){
	return this->clave;
}
