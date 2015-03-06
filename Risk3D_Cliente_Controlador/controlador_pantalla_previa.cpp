#include "controlador_pantalla_previa.h"
#include "vista_pantalla_previa.h"

static Log log("ControladorPantallaPrevia");

void ControladorPantallaPrevia::inicializar(){
	// no hacer nada.
}

void ControladorPantallaPrevia::manejar_evento_temporizador(){
	Mensaje* mensaje = get_contexto()->get_servidor()->get_mensaje();
	if(mensaje!=0){
		log.info("El controlador recibio: " + mensaje->get_descripcion());

		if(mensaje->es_de_tipo(TipoDeMensaje::juego_cancelado())){
			get_vista().cerrar();	
		} 
		else if(mensaje->es_de_tipo(TipoDeMensaje::juego_iniciado())){
			get_vista().mostrar_juego();	
		} 
		else if(mensaje->es_de_tipo(TipoDeMensaje::mensaje_de_sistema())){
			MensajeDeSistema* mensaje_de_sistema = dynamic_cast<MensajeDeSistema*>(mensaje);
			get_vista().mostrar_mensaje(mensaje_de_sistema->get_mensaje());	
		} 
		else if(mensaje->es_de_tipo(TipoDeMensaje::mensaje_de_error())){
			MensajeDeError* mensaje_de_error = dynamic_cast<MensajeDeError*>(mensaje);
			get_vista().mostrar_alerta(mensaje_de_error->get_mensaje());	
		}
		else if(mensaje->es_de_tipo(TipoDeMensaje::mensaje_de_chat())){
			MensajeDeChat* mensaje_de_chat = dynamic_cast<MensajeDeChat*>(mensaje);
			get_vista().mostrar_chat(mensaje_de_chat->get_imperio(), mensaje_de_chat->get_mensaje());	
		}

		delete mensaje;
	}
}

void ControladorPantallaPrevia::manejar_evento_chat(string mensaje){
	get_contexto()->get_servidor()->enviar(FabricaDeOrdenes::crear_orden_chatear(mensaje));
}

void ControladorPantallaPrevia::manejar_evento_comenzar_juego(){
	get_contexto()->get_servidor()->enviar(FabricaDeOrdenes::crear_orden_comenzar_juego());
}

void ControladorPantallaPrevia::manejar_evento_salir(){
	delete get_contexto()->get_servidor();
	get_contexto()->set_servidor(0);
	get_vista().cerrar();
}
