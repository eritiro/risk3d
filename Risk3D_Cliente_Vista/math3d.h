/* 
 * Adaptado  por Mariano M. Chouza de 'GraphicsGems.h'
 * Version 1.0 - Andrew Glassner
 * from "Graphics Gems", Academic Press, 1990
 */

#ifndef MATH3D_H_
#define MATH3D_H_

struct Point3 {	/* 3d point */
	double x, y, z;
};

typedef Point3 Vector3;

struct Plane {			/* Plane: ax + by + cz + d = 0	*/
	double	a ,b ,c, d;
};

const double PI = 3.1415926535897932384626433832795;

Vector3* V3Normalize(Vector3* v);
double V3Length(Vector3* a);
double V3Dot(Vector3* a, Vector3* b);
Vector3* V3Cross(Vector3* a, Vector3* b, Vector3* c);

#endif /* MATH3D_H_ */
