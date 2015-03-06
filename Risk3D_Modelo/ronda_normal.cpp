#include "ronda_normal.h"
#include "juego.h"

RondaNormal::RondaNormal(Juego& juego) : juego(juego){
}

void RondaNormal::ordenar_turnos(){
	
	juego.notificar_a_todos("Estableciendo el orden de los jugadores...");

	ContenedorJugadores jugadores = juego.get_jugadores();
	do{
		jugadores = this->tirar_dados(jugadores);
		if(jugadores.size() > 1)
			juego.notificar_a_todos("Hubo un empate, se vuelve a tirar.");
	}while(jugadores.size() > 1);
	
	Jugador* jugador_inicial = jugadores.front();
	juego.notificar_a_todos("Comienza " + jugador_inicial->get_nombre_emperador());

	//Busca al primer jugador:
	IteradorJugadores i =  juego.get_jugadores().begin();
	while(*i != jugador_inicial)
		i++;

	//Agrega a todos hasta el final de la lista:
	while(i !=  juego.get_jugadores().end())
	{
		imperios_ordenados.push_back((*i)->get_imperio());
		i++;
	}

	//Agrega a los del principio de la lista:
	i =  juego.get_jugadores().begin();
	while(*i != jugador_inicial)
	{
		imperios_ordenados.push_back((*i)->get_imperio());
		i++;
	}

	this->empezar_ronda();
}

Jugador* RondaNormal::get_primer_jugador(){
	return juego.get_jugador(this->imperios_ordenados.front());
}

Jugador* RondaNormal::get_jugador_actual(){
	if(iterador_imperios == imperios_ordenados.end())
		this->empezar_ronda();
	return juego.get_jugador(*iterador_imperios);
}

void RondaNormal::finalizar_turno(){
	if(iterador_imperios == imperios_ordenados.end())
		this->empezar_ronda();
	iterador_imperios++;
}

void RondaNormal::empezar_ronda(){
	iterador_imperios = imperios_ordenados.begin();
}

ContenedorJugadores RondaNormal::tirar_dados(ContenedorJugadores jugadores){

	int dados[MAXIMO_DE_IMPERIOS];

	// Cada uno tira un dado...
	int pos = 0;
	foreach(IteradorJugadores, i, jugadores){
		dados[pos] = juego.get_ambiente().generar_valor_aleatorio(1, 6);
		string nombre = (*i)->get_nombre_emperador();
		juego.notificar_a_todos(nombre + " obtuvo un " + UtilidadesString::int_a_string(dados[pos]));
		pos++;
	}
	
	// Busca el mayor valor:
	int mayor_valor = 0;
	for(pos = 0; pos< jugadores.size(); pos++){
		if(dados[pos] > mayor_valor)
			mayor_valor = dados[pos];
	}

	// Devuelve los que obtuvieron el mayor valor:
	pos = 0;
	ContenedorJugadores ganadores;
	foreach(IteradorJugadores, j, jugadores){
		if(dados[pos] == mayor_valor)
			ganadores.push_back(*j);
		pos++;
	}
	return ganadores;
}

