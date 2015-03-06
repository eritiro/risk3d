#include "utilidades_string.h"

char UtilidadesString::buffer[MEDIDA_BUFFER_CONVERSION_STRINGS] = "";

string UtilidadesString::int_a_string(int valor){
	string resultado;
	string signo;

	if(valor<0){
		signo = "-";
		valor = -valor;
	}
	else{
		signo = "";
	}
		
	do{
		int digito = (valor % 10);
		char caracter = digito + 48;
		resultado = caracter + resultado;
		valor/= 10;
	}while(valor != 0);

	return signo + resultado;
}

string UtilidadesString::int_a_string(int valor, int digitos){
	string resultado;
	for(int i = 0; i < digitos; i++){
		int digito = (valor % 10);
		char caracter = digito + 48;
		resultado = caracter + resultado;
		valor/= 10;
	}

	return resultado;
}

bool UtilidadesString::es_entero(string valor){
	//Comprueba que el string no sea vacio
	if(valor== "")
		return false;

	//Comprueba que los datos que contiene sean numericos
	foreach(string::iterator, i, valor){
		if((*i < '0') || (*i > '9'))
			return false;
	}
	// else
	return true;
}

int UtilidadesString::string_a_int(string valor){
	//Comprueba que el valor sea entero
	if(!es_entero(valor))
		throw ExcepcionDeParseo("No se puede convertir de string a int.");

	return atoi(valor.c_str());
}

string UtilidadesString::quitar_espacios(string valor){

	const char* c = valor.c_str();

	int ini = 0;
	int fin = valor.size() - 1;

	while(c[ini] == ' ')
		ini++;
	
	while((fin != ini) && (c[fin] == ' '))
		fin--;

	return valor.substr(ini, fin - ini);

}