#ifndef MACROS_H_
#define MACROS_H_

#define foreach(TipoIterador, iterador, coleccion) \
	for(TipoIterador iterador = (coleccion).begin(); iterador != (coleccion).end(); ++iterador)

#endif /* MACROS_H_ */
