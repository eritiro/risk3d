#include "excepcion_risk3d.h"

ExcepcionRisk3D::ExcepcionRisk3D(string descripcion) : std::logic_error(descripcion){
}

ExcepcionRisk3D::~ExcepcionRisk3D(){
}

string ExcepcionRisk3D::get_descripcion(){
	return this->what();
}
