#include "ciudad.h"

Ciudad::Ciudad(float latitud, float longitud, float h, Tropa* tropa, Color color)
	: lat(latitud), lon(longitud), h(h), color(color), tropa(tropa){

}

bool Ciudad::cityRayIntersection(Point3 rayStart, Vector3 rayDir){
	Point3 cityBase;
	Vector3 cityAxis;
	Plane bot, top;
	double in, out;
	int dummy;

	cityBase.x = cos(this->lat * PI / 180.0) * cos(this->lon * PI / 180.0);
	cityBase.y = cos(this->lat * PI / 180.0) * sin(this->lon * PI / 180.0);
	cityBase.z = sin(this->lat * PI / 180.0);

	cityAxis = cityBase;
	V3Normalize(&cityAxis);

	V3Normalize(&rayDir);

	if (!intcyl(&rayStart, &rayDir, &cityBase, &cityAxis, ANCHO_CIUDAD, &in, &out))
		return 0;

	bot.a = -cityAxis.x;
	bot.b = -cityAxis.y;
	bot.c = -cityAxis.z;
	bot.d = 1.0;
	top.a = cityAxis.x;
	top.b = cityAxis.y;
	top.c = cityAxis.z;
	top.d = -1.0 - this->h;

	return clipobj(&rayStart, &rayDir, &bot, &top, &in, &out, &dummy, &dummy);
}