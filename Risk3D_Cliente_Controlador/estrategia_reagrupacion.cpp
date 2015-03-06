#include "estrategia_reagrupacion.h"

void EstrategiaReagrupacion::inicializar_estrategia(ControladorPantallaJuego* controlador){
	controlador->get_vista().mostrar_instruccion("Seleccione el territorio del cual desea quitar ejercitos");
	controlador->get_vista().quitar_resaltado_de_territorios();
	this->selecciono_origen = false;
}

void EstrategiaReagrupacion::manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio){
	if(!this->selecciono_origen){
		this->desde = territorio;
		this->selecciono_origen = true;
		controlador->get_vista().mostrar_instruccion("Seleccione el territorio al cual desea agregar ejercitos");
		//controlador->get_vista().resaltar_territorios_adyacentes(territorio);
	}
	else{
		string respuesta = controlador->get_vista().preguntar("Seleccione la cantidad de ejercitos que desea mover");

		if(respuesta != ""){
			if(UtilidadesString::es_entero(respuesta)){
				int cantidad_ejercitos = UtilidadesString::string_a_int(respuesta);
				Territorio* hasta = territorio;
				controlador->get_contexto()->get_servidor()->enviar(
					FabricaDeOrdenes::crear_orden_reagrupar_ejercitos(desde, hasta, cantidad_ejercitos));
			}
			else{
				controlador->get_vista().mostrar_alerta("El valor debe ser numerico");
			}
		}

		this->inicializar_estrategia(controlador);
	}
}

void EstrategiaReagrupacion::manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador){
	this->inicializar_estrategia(controlador);	
}
