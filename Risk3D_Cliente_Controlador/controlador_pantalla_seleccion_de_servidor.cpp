#include "controlador_pantalla_seleccion_de_servidor.h"
#include "vista_pantalla_seleccion_de_servidor.h"


void ControladorPantallaSeleccionDeServidor::inicializar(){
	// no hace nada.
}

void ControladorPantallaSeleccionDeServidor::manejar_evento_aceptar(){
	int puerto;
	string nombre_servidor = get_vista().get_nombre_servidor();
	

	//chequea que se haya ingresado un servidor
	if (nombre_servidor == ""){
		this->get_vista().mostrar_alerta("Debe ingresar un servidor.");
		return;
	}


	//chequea que el puerto sea un valor entero
	try{
		puerto = UtilidadesString::string_a_int(this->get_vista().get_puerto_servidor());
	}
	catch(ExcepcionDeParseo){
		this->get_vista().mostrar_alerta("El numero de puerto no es correcto.");
		return;
	}

	this->get_vista().cerrar();


	try{
		//Quiero que el puntero carezca de validez cuando salga del scope
		ServidorRemoto servidor(nombre_servidor, puerto);
		servidor.comenzar();
		get_contexto()->set_servidor(&servidor);
		get_contexto()->set_es_creador_del_juego(false);
		this->get_vista().mostrar_seleccion_de_imperio();
	}
	catch(ExcepcionDeSocket){
		this->get_vista().mostrar_alerta("No se puede conectar al servidor");
	}
	get_contexto()->set_servidor(0);
}


void ControladorPantallaSeleccionDeServidor::manejar_evento_cancelar(){
	get_vista().cerrar();
}
