#ifndef PARSER_DE_PARAMETROS_H_
#define PARSER_DE_PARAMETROS_H_

// El compilador detecta un identificador de mas de 255 caracteres pero este es truncado en el 
// "browser information" y por lo tanto llena todo de warnings. Esto es porque el map es un template
// "asi de grande".
#pragma warning(disable:4786)
#include <map>
#include <string>
#include "excepcion_parseando_parametros.h"

using std::map;
using std::string;

typedef map<string, string> TablaParametros;

class ParserDeParametros {
	private:
		TablaParametros parametros;

	public:
		ParserDeParametros(int argc, char* argv[]);
		string leer(string clave);
};

#endif /* PARSER_DE_PARAMETROS_H_ */
