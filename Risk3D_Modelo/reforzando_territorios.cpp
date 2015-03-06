#include "reforzando_territorios.h"

ReforzandoTerritorios::ReforzandoTerritorios() : EstadoBelico("Reforzando territorios"){
}

void ReforzandoTerritorios::inicializar(Juego* juego){
	Imperio* imperio_actual = juego->get_jugador_actual()->get_imperio();
	imperio_actual->set_ejercitos_disponibles(0);
	agregar_ejercitos_refuerzo_por_territorio(imperio_actual, juego);
	agregar_ejercitos_refuerzo_por_continente(imperio_actual, juego);
	juego->actualizar();
}

EstadoDelJuego* ReforzandoTerritorios::proximo_estado(Orden& orden, Jugador* jugador, Juego* juego){
	OrdenReforzarTerritorio* ordenReforzarTerritorio = dynamic_cast<OrdenReforzarTerritorio*>(&orden);
	
	if (ordenReforzarTerritorio){
		ordenReforzarTerritorio->ejecutar(juego, jugador);
		return 0;
	}
	else
		return EstadoBelico::proximo_estado(orden, jugador, juego);
}

void ReforzandoTerritorios::agregar_ejercitos_refuerzo_por_territorio(Imperio* imperio, Juego* juego){
	int territorios_ocupados = imperio->get_tropas().size();
	int refuerzos_por_territorios;

	if(territorios_ocupados < 9)
		refuerzos_por_territorios = 3;
	else
		refuerzos_por_territorios = ((territorios_ocupados - 1) / 3) + 1;
	
	juego->notificar_a_todos(imperio->get_nombre_emperador() + " recibio " 
		+ UtilidadesString::int_a_string(refuerzos_por_territorios) + " ejercitos por sus territorios.");

	imperio->agregar_ejercitos_disponibles(refuerzos_por_territorios);
}

void ReforzandoTerritorios::agregar_ejercitos_refuerzo_por_continente(Imperio* imperio, Juego* juego){
	foreach(IteradorContinentes, continente, juego->get_info().get_mapa().get_continentes()){
		bool continente_pertenece_al_imperio = true;
		// recorre todos los territorios del continente
		foreach(IteradorTerritorios, territorio, (*continente)->get_territorios()){
			//si el imperio no es propietario del territorio
			if(!imperio->es_propietario_de(*territorio)){
				continente_pertenece_al_imperio = false;
				break;
			}
		}
		if(continente_pertenece_al_imperio){
			int bonus = (*continente)->get_bonus();
			string nombre_continente = (*continente)->get_nombre();
			juego->notificar_a_todos(imperio->get_nombre_emperador() + " recibio "
				+ UtilidadesString::int_a_string(bonus) + " ejercitos por poseer " + nombre_continente);
			imperio->agregar_ejercitos_disponibles(bonus);
		}
	}
}

EstadoDelJuego* ReforzandoTerritorios::proximo_estado_guerra(Juego* juego){
	juego->notificar_a_todos("El emperador " + juego->get_jugador_actual()->get_nombre_emperador()  + " ahora esta en estado de ataque.");
	return new Atacando();
}
