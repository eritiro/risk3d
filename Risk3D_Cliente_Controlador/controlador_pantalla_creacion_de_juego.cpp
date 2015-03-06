#include "controlador_pantalla_creacion_de_juego.h"
#include "vista_pantalla_creacion_de_juego.h"
#include "utilidades_string.h"

#include "fabrica_de_ordenes.h"


void ControladorPantallaCreacionDeJuego::inicializar(){
	// no hace nada.
}


void ControladorPantallaCreacionDeJuego::manejar_evento_aceptar(){
	string ruta_mapa = get_vista().get_ruta_mapa_seleccionado();
	int puerto;

	//chequea que se haya ingresado una ruta para el mapa
	if (ruta_mapa == ""){
		this->get_vista().mostrar_alerta("Debe ingresar la ruta del mapa.");
		return;
	}
	
	//chequea que el puerto sea un valor entero
	try{
		puerto = UtilidadesString::string_a_int(this->get_vista().get_puerto());
	}
	catch(ExcepcionDeParseo){
		this->get_vista().mostrar_alerta("El numero de puerto no es correcto.");
		return;
	}

	this->get_vista().cerrar();

	string comando_servidor = string(RUTA_SERVIDOR);
	comando_servidor += " mapa=" + ruta_mapa;
	comando_servidor += " puerto=" + UtilidadesString::int_a_string(puerto);
	comando_servidor += " verborragico=si"; 
	get_contexto()->set_hilo_servidor(new HiloEjecucion(comando_servidor));
	get_contexto()->get_hilo_servidor()->comenzar();

	//Se asegura que el puerto de escucha del servidor ya este levantado
	Thread::dormir(500);

	try{
		//Quiero que el puntero carezca de validez cuando salga del scope
		ServidorRemoto servidor(LOCALHOST, puerto);
		servidor.comenzar();
		get_contexto()->set_servidor(&servidor);
		get_contexto()->set_es_creador_del_juego(true);
		this->get_vista().mostrar_seleccion_de_imperio();
		servidor.enviar(FabricaDeOrdenes::crear_orden_cancelar_juego());
		get_contexto()->get_hilo_servidor()->unir();
	}
	catch(ExcepcionDeSocket){
		this->get_vista().mostrar_alerta("No se puede conectar al servidor");
	}
	get_contexto()->set_servidor(0);

}


void ControladorPantallaCreacionDeJuego::manejar_evento_cancelar(){
	get_vista().cerrar();
}


void ControladorPantallaCreacionDeJuego::manejar_evento_examinar(){
	string ruta_mapa = this->get_vista().solicitar_archivo("Seleccione un mapa...");
	if (ruta_mapa != ""){
		this->get_vista().set_ruta_mapa_seleccionado(ruta_mapa);
	}
}
