#pragma warning(disable:4786)

#include "repartidor_de_territorios.h"

void RepartidorDeTerritorios::repartir_territorios(Juego* juego){
	ContenedorTerritorios territorios;
	
	foreach(IteradorTerritorios, iterador_territorio, juego->get_info().get_mapa().get_territorios()){
		territorios.push_back(*iterador_territorio);
	}

	while(territorios.size() != 0){
		int posicion_territorio = juego->get_ambiente().generar_valor_aleatorio(0, territorios.size() -1) % territorios.size();

		Territorio* territorio = territorios[posicion_territorio];
		this->asignar_territorio(juego, territorio);
	
		IteradorTerritorios iterador = territorios.begin();
		for(int i = 0; i < posicion_territorio; i++)
			iterador++;
		territorios.erase(iterador);
	}
}

void RepartidorDeTerritorios::asignar_territorio(Juego* juego, Territorio* territorio){
	Imperio* imperio = juego->get_jugador_actual()->get_imperio();
	imperio->agregar_territorio(territorio, CANTIDAD_INICIAL_EJERCITOS_POR_TERRITORIO);
	juego->notificar_a_todos(imperio->get_nombre_emperador() + " obtuvo " + territorio->get_nombre());
	juego->get_ronda().finalizar_turno();
}
