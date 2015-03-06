#include "controlador_pantalla_seleccion_de_imperio.h"
#include "vista_pantalla_seleccion_de_imperio.h"

static Log log("ControladorPantallaSeleccionDeImperio");

void ControladorPantallaSeleccionDeImperio::inicializar(){
	// no hacer nada.
}

void ControladorPantallaSeleccionDeImperio::manejar_evento_temporizador(){
	Mensaje* mensaje = get_contexto()->get_servidor()->get_mensaje();
	
	if(mensaje!=0){
		log.info("El controlador recibio: " + mensaje->get_descripcion());

		if(mensaje->es_de_tipo(TipoDeMensaje::jugador_agregado())){
			EventoJugadorAgregado* evento_jugador_agregado = dynamic_cast<EventoJugadorAgregado*>(mensaje);
			this->get_contexto()->set_id_imperio(evento_jugador_agregado->get_imperio()->get_id());
			get_vista().mostrar_pantalla_previa_al_juego();
		}
		if(mensaje->es_de_tipo(TipoDeMensaje::juego_cancelado())){
			get_vista().mostrar_alerta("La conexion con el servidor se ha cerrado!");	
			get_vista().cerrar();
		} 
		else if(mensaje->es_de_tipo(TipoDeMensaje::juego_iniciado())){
			get_vista().mostrar_alerta("El juego ya se inicio sin ti!");	
			get_vista().cerrar();
		} 
		else if(mensaje->es_de_tipo(TipoDeMensaje::mensaje_de_error())){
			MensajeDeError* mensaje_de_error = dynamic_cast<MensajeDeError*>(mensaje);
			get_vista().mostrar_alerta(mensaje_de_error->get_mensaje());	
		}
		delete mensaje;
	}
}

void ControladorPantallaSeleccionDeImperio::manejar_evento_aceptar(){
	string nombre = get_vista().get_nombre_emperador();
	ColorImperio color = get_vista().get_color_imperio();
	
	if (nombre == ""){
		get_vista().mostrar_alerta("Debe ingresar un nombre.");
		return;
	}
	
	bool es_creador = get_contexto()->get_es_creador_del_juego();
	Orden* orden = FabricaDeOrdenes::crear_orden_agregar_jugador(nombre, color, es_creador);
	get_contexto()->get_servidor()->enviar(orden);
}


void ControladorPantallaSeleccionDeImperio::manejar_evento_cancelar(){
	get_vista().cerrar();
}