#include "constructor_de_juego.h"

ConstructorDeJuego::ConstructorDeJuego(Mapa& mapa){
	this->juego = new Juego(mapa);
	ronda = 0;
}

ConstructorDeJuego ConstructorDeJuego::crear_juego(Mapa& mapa){
	return ConstructorDeJuego(mapa);
}

ConstructorDeJuego ConstructorDeJuego::crear_juego(){
	Mapa* mapa = new Mapa();
	// esto trae consigo un memory leak!!!
	return crear_juego(*mapa);
}

Juego* ConstructorDeJuego::get_juego(){
	return this->juego;
}


ConstructorDeJuego ConstructorDeJuego::agregar_jugador(){
	return agregar_jugador(new JugadorDePrueba());
}

ConstructorDeJuego ConstructorDeJuego::agregar_jugador(Jugador* jugador){
	string nombre = "Emperador #" + UtilidadesString::int_a_string(juego->get_info().get_imperios().size());
	ColorImperio color = (ColorImperio)juego->get_info().get_imperios().size();
	Imperio* imperio = new Imperio(generar_id(juego->get_info().get_imperios()), nombre, color);
	jugador->set_imperio(imperio);
	juego->get_info().get_imperios().push_back(imperio);
	juego->get_jugadores().push_back(jugador);
	return *this;
}

ConstructorDeJuego ConstructorDeJuego::asignar_territorio(Territorio* territorio, Jugador* jugador, int cantidad_ejercitos){
	jugador->get_imperio()->agregar_territorio(territorio, cantidad_ejercitos);
	return *this;
}

ConstructorDeJuego ConstructorDeJuego::en_estado(EstadoDelJuego* estado){
	juego->set_componente_estado(estado);
	return *this;
}

ConstructorDeJuego ConstructorDeJuego::es_el_turno_de(Jugador* jugador){
	ronda = new RondaDePrueba(jugador);
	juego->set_componente_ronda(ronda);
	return *this;
}

ConstructorDeJuego ConstructorDeJuego::despues_juega(Jugador* jugador){
	ronda->set_siguiente_jugador(jugador);
	return *this;
}

ConstructorDeJuego ConstructorDeJuego::usando_estos_dados(int d1, int d2, int d3, int d4){
	int valores[] = {d1, d2, d3, d4};
	AmbienteDePrueba* ambiente = new AmbienteDePrueba(valores);
	juego->set_componente_ambiente(ambiente);
	return *this;
}
