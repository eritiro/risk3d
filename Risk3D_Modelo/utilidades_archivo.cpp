#include "utilidades_archivo.h"

bool UtilidadesArchivo::existe_archivo(string ruta_archivo){
	std::ifstream archivo(ruta_archivo.c_str(), std::ios_base::binary);
	return archivo.is_open();
}
