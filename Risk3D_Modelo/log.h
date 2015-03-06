#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <exception>
#include "lock.h"

using std::string;
using std::exception;

class Log {
	static Mutex mutex;
	static bool habilitado;
	
	string donde;
	void logear(string contenido);
public:
	Log(string donde);
	void info(string informacion);
	void alerta(string mensaje);
	void excepcion(exception&);

	static void set_logueo_por_consola(bool valor);
};


#endif /* LOG_H_ */
