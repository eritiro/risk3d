#include "estrategia_refuerzo.h"

void EstrategiaRefuerzo::inicializar_estrategia(ControladorPantallaJuego* controlador){
	controlador->get_vista().mostrar_instruccion("Seleccione el territorio que desea reforzar");
	controlador->get_vista().quitar_resaltado_de_territorios();
}

void EstrategiaRefuerzo::manejar_evento_territorio_seleccionado(ControladorPantallaJuego* controlador, Territorio* territorio){
	string respuesta = controlador->get_vista().preguntar("Seleccione cuantos ejercitos desea agregar");

	if(respuesta != ""){
		if(!UtilidadesString::es_entero(respuesta))
			controlador->get_vista().mostrar_alerta("El valor debe ser numerico");
		else{
			int ejercitos = UtilidadesString::string_a_int(respuesta);
			controlador->get_contexto()->get_servidor()->enviar(FabricaDeOrdenes::crear_orden_reforzar_territorio(territorio, ejercitos));
		}
	}
}

void EstrategiaRefuerzo::manejar_evento_territorio_deseleccionado(ControladorPantallaJuego* controlador){
	this->inicializar_estrategia(controlador);	
}
