#pragma warning(disable:4786)

#include "repartidor_de_objetivos.h"

static Log log("RepartidorDeObjetivos");

RepartidorDeObjetivos::RepartidorDeObjetivos(ConfiguracionMapa& configuracion, AmbienteDeJuego& ambiente, InfoJuego& info)
: configuracion(configuracion), ambiente(ambiente), info(info){
}

void RepartidorDeObjetivos::repartir_objetivos(ContenedorJugadores& jugadores){

	// crea los objetivos de ocupacion
	ContenedorObjetivos objetivos = this->crear_objetivos_de_ocupacion(configuracion.get_requisitos_de_ocupacion());

	// si hace falta, agrega los objetivos de destruccion
	if(configuracion.hay_objetivos_de_destruccion())
		this->agregar_objetivos_de_destruccion(objetivos, jugadores);


	int cantidad_jugadores = jugadores.size();
	int cantidad_objetivos = objetivos.size();

	if(cantidad_objetivos < cantidad_jugadores)
		throw ExcepcionDeNegocio("No hay suficientes objetivos para los jugadores.");

	foreach(IteradorJugadores, i, jugadores){
		this->asignar_objetivo(*i, objetivos);
	}

	// borra los objetivos no asignados
	foreach(IteradorObjetivos, objetivo, objetivos)
		delete *objetivo;
}

ContenedorObjetivos RepartidorDeObjetivos::crear_objetivos_de_ocupacion(ContenedorRequisitos requisitos){
	ContenedorObjetivos objetivos;
	foreach(IteradorRequisitos, requisito, requisitos)
		objetivos.push_back(new ObjetivoDeOcupacion(*requisito));

	return objetivos;
}

void RepartidorDeObjetivos::agregar_objetivos_de_destruccion(ContenedorObjetivos& objetivos, ContenedorJugadores& jugadores){
	foreach(IteradorJugadores, jugador, jugadores)
		objetivos.push_back(new ObjetivoDeDestruccion((*jugador)->get_imperio()));
}

void RepartidorDeObjetivos::asignar_objetivo(Jugador* jugador, ContenedorObjetivos& objetivos){


	Objetivo* objetivo = this->buscar_objetivo(jugador, objetivos);
	jugador->set_objetivo(objetivo);

	// quita al objetivo usado de la lista. 
	// Nota: El objetivo global no esta en la lista, por lo tanto no lo va a quitar. Eso esta bien.
	foreach(IteradorObjetivos, i, objetivos){
		if(*i == objetivo){
			objetivos.erase(i);
			break;
		}
	}
}

Objetivo* RepartidorDeObjetivos::buscar_objetivo(Jugador* jugador, ContenedorObjetivos& objetivos){
	int valor_inicial_aleatorio = ambiente.generar_valor_aleatorio(0, objetivos.size() -1);
	int i = valor_inicial_aleatorio;

	while(!objetivos[i]->es_valido(jugador->get_imperio(), &info)){
		i++;

		// cuando llega al final, vuelve al principio del contenedor
		if(i == objetivos.size())
			i = 0;

		// si vuelve al valor inicial significa que no existe ningun objetivo valido para el jugador
		if(i == valor_inicial_aleatorio){
			log.alerta("No existe ningun objetivo valido para " + jugador->get_nombre_emperador() + ". Se le asignara un objetivo global.");
			return Objetivo::get_objetivo_global();
		}

	}

	return objetivos[i];

}
