#include "controlador_pantalla_juego.h"
#include "vista_pantalla_juego.h"

#include "manejador_mensaje_de_sistema.h"
#include "manejador_mensaje_de_error.h"
#include "manejador_mensaje_de_chat.h"
#include "manejador_mensaje_juego_cancelado.h"
#include "manejador_mensaje_juego_terminado.h"
#include "manejador_mensaje_actualizacion.h"
#include "manejador_mensaje_batalla_producida.h"
#include "manejador_mensaje_defensa_requerida.h"
#include "manejador_mensaje_objetivo_secreto.h"

#include "estrategia_sin_seleccion.h"
#include "estrategia_refuerzo.h"
#include "estrategia_ataque.h"
#include "estrategia_reagrupacion.h"


static Log log("ControladorPantallaJuego");

ControladorPantallaJuego::ControladorPantallaJuego(){
	registrar_manejador(TipoDeMensaje::mensaje_de_sistema(), new ManejadorMensajeDeSistema());
	registrar_manejador(TipoDeMensaje::mensaje_de_error(), new ManejadorMensajeDeError());
	registrar_manejador(TipoDeMensaje::mensaje_de_chat(), new ManejadorMensajeDeChat());
	registrar_manejador(TipoDeMensaje::juego_cancelado(), new ManejadorMensajeJuegoCancelado());
	registrar_manejador(TipoDeMensaje::juego_terminado(), new ManejadorMensajeJuegoTerminado());
	registrar_manejador(TipoDeMensaje::actualizacion(), new ManejadorMensajeActualizacion());
	registrar_manejador(TipoDeMensaje::batalla_producida(), new ManejadorMensajeBatallaProducida());
	registrar_manejador(TipoDeMensaje::defensa_requerida(), new ManejadorMensajeDefensaRequerida());
	registrar_manejador(TipoDeMensaje::mensaje_objetivo_secreto(), new ManejadorMensajeObjetivoSecreto());
	estrategia_de_juego = 0;
}

ControladorPantallaJuego::~ControladorPantallaJuego(){
	foreach(IteradorManejadoresDeMensajes, i, this->tablaManejadoresDeMensajes)
		delete i->second;
	if(estrategia_de_juego)
		delete estrategia_de_juego;
}

void ControladorPantallaJuego::set_objetivo_secreto(string valor){
	this->objetivo_secreto = valor;
}

// Manejo de eventos del usuario

void ControladorPantallaJuego::inicializar(){
	this->cambiar_estrategia(new EstrategiaSinSeleccion());
}

void ControladorPantallaJuego::manejar_evento_temporizador(){
	Mensaje* mensaje = get_contexto()->get_servidor()->get_mensaje();
	if(mensaje!=0)
		this->manejar_mensaje(mensaje);
}

void ControladorPantallaJuego::manejar_evento_reforzar(){
	this->cambiar_estrategia(new EstrategiaRefuerzo());
}

void ControladorPantallaJuego::manejar_evento_atacar(){
	this->cambiar_estrategia(new EstrategiaAtaque());
}

void ControladorPantallaJuego::manejar_evento_reagrupar(){
	this->cambiar_estrategia(new EstrategiaReagrupacion());
}

void ControladorPantallaJuego::manejar_evento_territorio_seleccionado(Territorio* territorio){
	this->estrategia_de_juego->manejar_evento_territorio_seleccionado(this, territorio);
}

void ControladorPantallaJuego::manejar_evento_territorio_deseleccionado(){
	this->estrategia_de_juego->manejar_evento_territorio_deseleccionado(this);
}

void ControladorPantallaJuego::manejar_evento_fin_de_turno(){
	this->get_contexto()->get_servidor()->enviar(FabricaDeOrdenes::crear_orden_terminar_turno());
}

void ControladorPantallaJuego::manejar_evento_chat(string mensaje){
	this->get_contexto()->get_servidor()->enviar(FabricaDeOrdenes::crear_orden_chatear(mensaje));
}


// Metodos privados

void ControladorPantallaJuego::manejar_mensaje(Mensaje* mensaje){
	log.info("El controlador recibio: " + mensaje->get_descripcion());

	ManejadorDeMensajes* manejador = tablaManejadoresDeMensajes[mensaje->get_tipo().get_clave()];

	if(manejador==0){
		string alerta;
		alerta += "El controlador del juego no sabe como manejar el mensaje recibido.";
		alerta += " Mensaje: Tipo = " + mensaje->get_tipo().get_clave() + ".";
		alerta += " Descripcion = " + mensaje->get_descripcion() + ".";
		log.alerta(alerta);
	}
	else{
		manejador->manejar_mensaje(*mensaje, *this);
	}

	delete mensaje;
}

void ControladorPantallaJuego::registrar_manejador(TipoDeMensaje tipo, ManejadorDeMensajes* manejador){
	tablaManejadoresDeMensajes[tipo.get_clave()] = manejador;
}

void ControladorPantallaJuego::cambiar_estrategia(EstrategiaDeJuego* estrategia){
	if(estrategia_de_juego)
		delete estrategia_de_juego;
	this->estrategia_de_juego = estrategia;
	estrategia->inicializar_estrategia(this);
}


void ControladorPantallaJuego::manejar_evento_mostrar_acerca_de(){
	this->get_vista().abrir_ventana_acerca_de();
}


void ControladorPantallaJuego::manejar_evento_mostrar_objetivo(){
	if (this->objetivo_secreto != "")
		this->get_vista().abrir_ventana_mostrar_objetivo(objetivo_secreto);
	else
		this->get_vista().mostrar_alerta("No se conoce ningun objetivo");
}


void ControladorPantallaJuego::manejar_evento_cambiar_modo_vista(){
	this->get_vista().cambiar_modo_vista(get_contexto()->get_servidor()->get_info());
}