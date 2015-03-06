#include "info_juego.h"

InfoJuego::InfoJuego(Mapa& mapa) : mapa(mapa){
}

InfoJuego::~InfoJuego(){
	foreach(IteradorImperios, i, imperios)
		delete *i;
}

ContenedorImperios& InfoJuego::get_imperios(){
	return this->imperios;
}

Mapa& InfoJuego::get_mapa(){
	return this->mapa;
}

Imperio* InfoJuego::get_imperio(int id){
	foreach(IteradorImperios, i, imperios){
		if((*i)->get_id() == id)
			return *i;
	}
	//else
	return 0;
}

Imperio* InfoJuego::get_propietario(Territorio* territorio){
	foreach(IteradorImperios, i, imperios){
		if((*i)->es_propietario_de(territorio))
			return *i;
	}
	//else
	return 0;
}

Tropa* InfoJuego::get_tropa(Territorio* territorio){
	foreach(IteradorImperios, i, imperios){
		Tropa* tropa = (*i)->get_tropa(territorio); 
		if(tropa)
			return tropa;
	}
	//else
	return 0;
}
