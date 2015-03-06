#include "log.h"
#include <iostream>
//#include <windows.h>

using std::cout;
using std::endl;

Mutex Log::mutex;
bool Log::habilitado = true;

Log::Log(string donde) : donde(donde){
}

static void set_color(int color){
	//HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute (hConsoleHandle, color);
}

void Log::info(string informacion){
	set_color(7);
	logear(informacion);
}

void Log::alerta(string mensaje){
	set_color(12);
	logear(mensaje);
}

void Log::excepcion(exception& ex){
	set_color(7);
	logear("Ocurrio la siguiente excepcion: ");
	set_color(12);
	logear(string(ex.what()));
}

void Log::logear(string contenido){
	if(habilitado){
		Lock lock(mutex);
		cout << donde << "-> " << contenido << endl;
	}
}

void Log::set_logueo_por_consola(bool valor){
	habilitado = valor;
}
