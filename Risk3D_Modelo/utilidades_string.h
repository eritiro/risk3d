#ifndef UTILIDADES_STRING_H_
#define UTILIDADES_STRING_H_

#define MEDIDA_BUFFER_CONVERSION_STRINGS 2048

#include <string>
#include "macros.h"
#include "excepcion_de_parseo.h"

using std::basic_istream;
using std::string;

class UtilidadesString {
	private:
		static char buffer[MEDIDA_BUFFER_CONVERSION_STRINGS];
	public:
		// Transforma un entero a un string.
		static string int_a_string(int valor);
		// Transforma un entero a un string con una cantidad de digitos fijos.
		// Si el valor representado en string ocupa mas que esos digitos muestra 
		// los menos significativos, de lo contrario llena con ceros hasta 
		// completar.
		static string int_a_string(int valor, int digitos);
		static int string_a_int(string valor);
		static bool es_entero(string valor);
		static string quitar_espacios(string valor);
		template<class T> static string leer_linea(basic_istream<T> flujo){
			flujo.getline((char*)&buffer, MEDIDA_BUFFER_CONVERSION_STRINGS);
			return string((char*)&buffer);
		}
};


#endif /* UTILIDADES_STRING_H_ */
