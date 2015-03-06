#include "controlador_editor_de_mapa.h"
#include "vista_editor_de_mapa.h"



void ControladorEditorDeMapa::inicializar()
{
	estrategia_de_edicion = new EstrategiaSinSeleccion();
	get_vista().mostrar_mensaje_barra_estado("Editor de mapas. RISK 3D.");
}


ControladorEditorDeMapa::~ControladorEditorDeMapa(){
	delete(estrategia_de_edicion);
}

void ControladorEditorDeMapa::manejar_evento_destruir_ventana_principal(){
	get_vista().destruir_ventana_principal();
}


void ControladorEditorDeMapa::manejar_evento_nuevo_mapa(){
	if (!this->get_contexto()->hay_mapa_activo()){
		string ruta_textura = get_vista().solicitar_archivo("Seleccione textura...");
		if(ruta_textura!= ""){
			this->get_contexto()->set_mapa(new Mapa());
			this->get_mapa().set_ruta_textura(ruta_textura);
			this->get_vista().mostrar_textura(ruta_textura);
			this->get_contexto()->set_mapa_activo(true);
			this->get_contexto()->set_mapa_inicialmente_guardado(false);
			this->get_contexto()->set_mapa_modificado(false);
		}
	}
	else
		get_vista().mostrar_mensaje_alerta("Ya se encuentra trabajando\nen un mapa.");
}


void ControladorEditorDeMapa::manejar_evento_abrir_mapa(){
	try{
		if (!this->get_contexto()->hay_mapa_activo()){
			string ruta_mapa = get_vista().solicitar_archivo("Seleccione un mapa...");
			if (ruta_mapa != ""){
				this->ruta_archivo = ruta_mapa;

				this->get_contexto()->set_mapa(this->leer_mapa(ruta_mapa));
				this->get_contexto()->get_mapa().set_ruta_textura(this->get_contexto()->get_mapa().get_ruta_textura());
				this->get_vista().mostrar_textura(this->get_contexto()->get_mapa().get_ruta_textura());
				this->get_contexto()->set_mapa_inicialmente_guardado(true);
				this->get_contexto()->set_mapa_modificado(false);
				this->get_contexto()->set_mapa_activo(true);
				this->get_vista().refrescar_mapa(&this->get_mapa());
			}
		}
		else
			get_vista().mostrar_mensaje_alerta("Ya se encuentra trabajando\nen un mapa.");
	}
	catch(ExcepcionRisk3D ex){
		get_vista().mostrar_mensaje_alerta(ex.get_descripcion());
	}

}



void ControladorEditorDeMapa::manejar_evento_guardar_como_mapa(){
	if (this->get_contexto()->hay_mapa_activo()){
		string ruta_archivo = get_vista().solicitar_archivo("Guardar mapa como...");
		if (ruta_archivo != ""){
			this->ruta_archivo = ruta_archivo;
			this->guardar_mapa();
			this->get_contexto()->set_mapa_inicialmente_guardado(true);
			this->get_contexto()->set_mapa_modificado(false);
		}
	}
}


void ControladorEditorDeMapa::manejar_evento_guardar_mapa(){
	/* Si hay un mapa activo... */
	if (this->get_contexto()->hay_mapa_activo()){
		/* Si fue "guardado como" al menos una vez... */
		if (this->get_contexto()->fue_guardado_inicialmente_mapa()){
			/* Si hubo modificaciones sobre el mapa activo... */
			if (this->get_contexto()->fue_modificado_mapa()){
				this->guardar_mapa();
				this->get_contexto()->set_mapa_modificado(false);
			}
		}
		else /* Si el mapa no fue inicialmente guardado... */
		{
			this->manejar_evento_guardar_como_mapa();
		}
	}
}

void ControladorEditorDeMapa::guardar_mapa(){
	EscritorDeXml escritor;
	SerializadorMapa serializador;
	serializador.serializar(escritor, this->get_contexto()->get_mapa());
	escritor.guardar_archivo(ruta_archivo);
}

void ControladorEditorDeMapa::manejar_evento_cerrar_mapa(){
	/* Si hay un mapa activo... */
	if (this->get_contexto()->hay_mapa_activo()){
		bool respuesta_guardar = false;
		/* Si no quedan modificaciones por guardar... */
		if (this->get_contexto()->fue_modificado_mapa()){
			respuesta_guardar = get_vista().elegir_respuesta("Desea guardar los cambios antes de cerrar el mapa?");
		}

		if (respuesta_guardar){
			this->manejar_evento_guardar_mapa();
		}

		this->get_contexto()->set_mapa(0);
		get_vista().ocultar_textura();
		this->get_contexto()->set_mapa_activo(false);
	}
}


void ControladorEditorDeMapa::manejar_evento_salir_editor(){
	/* Si no hay un mapa activo... */ 
	if (!this->get_contexto()->hay_mapa_activo()){
		get_vista().destruir_ventana_principal();
	}
	else
		get_vista().mostrar_mensaje_alerta("Existe un mapa activo.\nCierrelo antes de salir.");
}


void ControladorEditorDeMapa::manejar_evento_crear_continente(){
	if (this->get_contexto()->hay_mapa_activo())
		get_vista().abrir_ventana_crear_continente();
}


void ControladorEditorDeMapa::manejar_evento_modificar_continente(){
	if (this->get_contexto()->hay_mapa_activo()){
		get_vista().abrir_ventana_modificar_continente();
	}	
}


void ControladorEditorDeMapa::manejar_evento_eliminar_continente(){
	if (this->get_contexto()->hay_mapa_activo()){
		get_vista().abrir_ventana_eliminar_continente();
		get_vista().refrescar_mapa(&this->get_mapa());
	}
}


void ControladorEditorDeMapa::manejar_evento_edicion(int x, int y){
	estrategia_de_edicion->efectuar_edicion(this, Coordenada(x,y));
}


void ControladorEditorDeMapa::manejar_evento_edicion(Territorio* territorio){
	estrategia_de_edicion->efectuar_edicion(this, territorio);
}


void ControladorEditorDeMapa::manejar_evento_modo_editar_territorio(){
	delete(this->estrategia_de_edicion);
	this->estrategia_de_edicion = new EstrategiaEdicionTerritorio();
}


void ControladorEditorDeMapa::manejar_evento_modo_editar_adyacencias(){
	delete(this->estrategia_de_edicion);
	this->estrategia_de_edicion = new EstrategiaEdicionAdyacencia();
}


Mapa* ControladorEditorDeMapa::leer_mapa(string nombre_archivo){
	SerializadorMapa serializador_mapa;
	LectorDeXml lector = LectorDeXml::crear_lector_desde_archivo(nombre_archivo);
	return serializador_mapa.deserializar(lector);
}


void ControladorEditorDeMapa::manejar_evento_modo_eliminar_territorio(){
	delete(this->estrategia_de_edicion);
	this->estrategia_de_edicion = new EstrategiaEliminarTerritorio();
}


void ControladorEditorDeMapa::manejar_evento_administrar_objetivos(){
	if (this->get_contexto()->hay_mapa_activo())
		this->get_vista().abrir_ventana_administrar_objetivos();
	else
		this->get_vista().mostrar_mensaje_alerta("Debe haber un mapa en edicion.");
}


void ControladorEditorDeMapa::manejar_evento_mostrar_acerca_de(){
	this->get_vista().abrir_ventana_acerca_de();
}