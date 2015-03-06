#include "batalla.h"
#include "juego.h"


Batalla::Batalla(Tropa* tropa_agresora, int ejercitos_ataque, Tropa* tropa_agredida){
	this->tropa_agresora = tropa_agresora;
	this->tropa_agredida = tropa_agredida;
	this->ejercitos_ataque = ejercitos_ataque;
}

Batalla::Batalla(Tropa* tropa_agresora, int ejercitos_ataque, Tropa* tropa_agredida, int ejercitos_defensa){
	this->tropa_agresora = tropa_agresora;
	this->tropa_agredida = tropa_agredida;
	this->ejercitos_ataque = ejercitos_ataque;
	this->ejercitos_defensa = ejercitos_defensa;
}

Tropa* Batalla::get_tropa_agresora(){
	return this->tropa_agresora;
}

Tropa* Batalla::get_tropa_agredida(){
	return this->tropa_agredida;
}

int Batalla::get_ejercitos_ataque(){
	return this->ejercitos_ataque;
}

void Batalla::set_ejercitos_defensa(int valor){
	this->ejercitos_defensa = valor;
}

void Batalla::ejecutar(Juego* juego){

	Jugador* jugador_agresor = juego->get_jugador(tropa_agresora->get_imperio());	
	Territorio* territorio_agresor = tropa_agresora->get_territorio();
	string nombre_territorio_atacante = territorio_agresor->get_nombre();
	Imperio* imperio_agresor = tropa_agresora->get_imperio();

	Jugador* jugador_agredido = juego->get_jugador(tropa_agredida->get_imperio());
	Territorio* territorio_agredido= tropa_agredida->get_territorio();	
	string nombre_territorio_defensor = territorio_agredido->get_nombre();
	Imperio* imperio_agredido = tropa_agredida->get_imperio();

	juego->notificar_a_todos("Comenzo la batalla!! " + nombre_territorio_atacante + " vs. " + nombre_territorio_defensor);

	
	ContenedorDados dados_atacante;
	for(int i = 0; i < ejercitos_ataque; i++){
		int dado = juego->get_ambiente().generar_valor_aleatorio(1, 6);
		juego->notificar_a_todos(imperio_agresor->get_nombre_emperador() + " obtuvo " + UtilidadesString::int_a_string(dado));
		dados_atacante.push_back(dado);
	}

	ContenedorDados dados_defensor;
	for(i = 0; i < ejercitos_defensa; i++){
		int dado = juego->get_ambiente().generar_valor_aleatorio(1, 6);
		juego->notificar_a_todos(imperio_agredido->get_nombre_emperador() + " obtuvo " + UtilidadesString::int_a_string(dado));
		dados_defensor.push_back(dado);
	}

	dados_atacante.sort();
	dados_atacante.reverse();
	dados_defensor.sort();
	dados_defensor.reverse();

	int ejercitos_a_destruir = ejercitos_ataque < ejercitos_defensa ? ejercitos_ataque : ejercitos_defensa;

	int ejercitos_caidos_atacante = 0;
	int ejercitos_caidos_defensor = 0;

	ContenedorDados::iterator iterador_dados_atacante = dados_atacante.begin();
	ContenedorDados::iterator iterador_dados_defensor = dados_defensor.begin();

	for(i = 0; i < ejercitos_a_destruir; i++){
		if(*iterador_dados_atacante > *iterador_dados_defensor){
			juego->notificar_a_todos("Cayo un ejercito de " + nombre_territorio_defensor);
			ejercitos_caidos_defensor++;
		}
		else{
			juego->notificar_a_todos("Cayo un ejercito de " + nombre_territorio_atacante);
			ejercitos_caidos_atacante++;
		}

		iterador_dados_atacante++;
		iterador_dados_defensor++;
	}

	// le resto ejercitos a las tropas
	tropa_agresora->agregar_ejercitos(-ejercitos_caidos_atacante);
	tropa_agredida->agregar_ejercitos(-ejercitos_caidos_defensor);

	jugador_agresor->recibir_mensaje(FabricaDeMensajes::crear_evento_batalla_producida(
		territorio_agresor, ejercitos_caidos_atacante, territorio_agredido, ejercitos_caidos_defensor));

	jugador_agredido->recibir_mensaje(FabricaDeMensajes::crear_evento_batalla_producida(
		territorio_agresor, ejercitos_caidos_atacante, territorio_agredido, ejercitos_caidos_defensor));

	// Chequea si se destruyo la tropa
	if(tropa_agredida->get_ejercitos() == 0){
		// Calcula los ejercitos sobrevivientes que van a poblar al territorio conquistado
		int sobrevivientes = ejercitos_ataque - ejercitos_caidos_atacante;
		imperio_agredido->abandonar_territorio(territorio_agredido);
		imperio_agresor->agregar_territorio(territorio_agredido, sobrevivientes);
		// Quita a los sobrevivientes de su tropa anterior.
		tropa_agresora->agregar_ejercitos(-sobrevivientes);
		juego->notificar_a_todos(imperio_agresor->get_nombre_emperador() +  " obtuvo " + nombre_territorio_defensor);
	}

	juego->actualizar();

}
