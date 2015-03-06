#ifndef ERROR_H_
#define ERROR_H_

#include <gtk/gtk.h>
#include <string>

using namespace std;


/* *
 * Declaracion de la clase Eerror encargada de mostrar al
 * usuario mensajes de errores.
 * */
 
class Error {
		
	public:
		Error(string error);
		~Error();
};

#endif /* ERROR_H_ */
