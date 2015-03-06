#include "parser_de_parametros.h"

ParserDeParametros::ParserDeParametros(int argc, char* argv[]){
	for(int i = 1; i < argc; i++){
		string par = argv[i];
		int pos = par.find("=");
		if((pos <= 0) || (pos == par.length()))
			throw ExcepcionParseandoParametros("El formato de los parametros no es correcto");

		string clave = par.substr(0, pos);
		string valor = par.substr(pos + 1, par.length());

		this->parametros[clave] = valor;
	}
}

string ParserDeParametros::leer(string clave){
	return parametros[clave];
}
