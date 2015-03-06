#ifndef CIUDAD_H_
#define CIUDAD_H_

#include "ray_cyl.h"
#include "math.h"
#include "color.h"
#include "tropa.h"
#include "constantes_vista.h"

class Ciudad {
	private:
		float lat;
		float lon;
		float h;
		Tropa* tropa;
		Color color;

	public:

		//to do: hacer un constructor mas simpatico.

		Ciudad(float latitud, float longitud, float altura, Tropa* tropa, Color color);

		bool cityRayIntersection(Point3 rayStart, Vector3 rayDir);

		float get_latitud(){return lat;}
		float get_longitud(){return lon;}
		
		float get_altura(){return h;}
		void set_altura(float valor){ this->h = valor;}

		Color get_color(){return color;}
		void set_color(Color valor){ this->color = valor;}
		
		Tropa* get_tropa(){return tropa;}
};

#endif /* CIUDAD_H_ */
