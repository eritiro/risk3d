#ifndef UTILIDADES_ARCHIVO_H_
#define UTILIDADES_ARCHIVO_H_

#include <string>
#include <fstream>

using std::string;

class UtilidadesArchivo {
	public:
		static bool existe_archivo(string ruta_archivo);
};


#endif /* UTILIDADES_ARCHIVO_H_ */
