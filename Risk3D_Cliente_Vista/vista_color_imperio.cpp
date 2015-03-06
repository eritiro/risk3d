#include "vista_color_imperio.h"

VistaColorImperio::VistaColorImperio(ColorImperio color_imperio) 
	: color_imperio(color_imperio) {
}

#pragma warning(REFACTORIZAME QUE AGONIZO DE DOLOR)
VistaColorImperio::VistaColorImperio(string color) {
	if(color == "Rojo")
		color_imperio = ROJO;
	else if(color == "Verde")
		color_imperio = VERDE;
	else if(color == "Azul")
		color_imperio = AZUL;
	else if(color == "Naranja")
		color_imperio = NARANJA;
	else if(color == "Rosa")
		color_imperio = ROSA;
	else if(color == "Turquesa")
		color_imperio = TURQUESA;
	else 
		throw ExcepcionColorInvalido("El color de imperio no es válido.");
}

#pragma warning(MAS GRASSA QUE LA LAMBADA)
string VistaColorImperio::get_string_color(){
	switch(color_imperio){
	case ROJO:
		return "Rojo";
		break;
	case VERDE:
		return "Verde";
		break;
	case AZUL:
		return "Azul";
		break;
	case NARANJA:
		return "Naranja";
		break;
	case ROSA:
		return "Rosa";
		break;
	case TURQUESA:
		return "Turquesa";
		break;
	default:
		throw ExcepcionColorInvalido("El color de imperio no es válido.");
	}
}

ColorImperio VistaColorImperio::get_color_imperio(){
	return this->color_imperio;
}

#pragma warning(MAS GRASA QUE EL MORCIPAN)
Color VistaColorImperio::get_color_rgb(){
	switch(color_imperio){
	case ROJO:
		return Color(1, 0, 0);
		break;
	case VERDE:
		return Color(0, 1, 0);
		break;
	case AZUL:
		return Color(0, 0, 1);
		break;
	case NARANJA:
		return Color(1, 0.5F, 0);
		break;
	case ROSA:
		return Color(0.91F, 0.41F, 0.93F);
		break;
	case TURQUESA:
		return Color(0.4F, 0.83F, 0.85F);
		break;
	default:
		throw ExcepcionColorInvalido("El color de imperio no es válido.");
	}
}
