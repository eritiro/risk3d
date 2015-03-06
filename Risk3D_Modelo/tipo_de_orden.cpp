#include "tipo_de_orden.h"

TipoDeOrden::TipoDeOrden(string clave) : clave(clave){
}

string TipoDeOrden::get_clave(){
	return this->clave;
}

TipoDeOrden::operator==(const TipoDeOrden& un_tipo, const TipoDeOrden& otro_tipo){
	return un_tipo.clave == otro_tipo.clave;
}
