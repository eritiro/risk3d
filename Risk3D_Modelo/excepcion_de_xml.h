#ifndef EXCEPCION_DE_XML_H_
#define EXCEPCION_DE_XML_H_

#include "excepcion_risk3d.h"

class ExcepcionDeXml : public ExcepcionRisk3D {
	public:
		ExcepcionDeXml(string descripcion) : ExcepcionRisk3D(descripcion){
		}
		virtual ~ExcepcionDeXml(){
		}
};

#endif /* EXCEPCION_DE_XML_H_ */
