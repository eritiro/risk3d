#ifndef EXCEPCION_RISK_3D_H_
#define EXCEPCION_RISK_3D_H_

#include <stdexcept>
#include <string>

using std::exception;
using std::string;

// Clase base para todas las excepciones de la aplicación.
class ExcepcionRisk3D : public std::logic_error {
	public:
		ExcepcionRisk3D(string descripcion);
		virtual ~ExcepcionRisk3D();
		string get_descripcion();
};


#endif /* EXCEPCION_RISK_3D_H_ */
