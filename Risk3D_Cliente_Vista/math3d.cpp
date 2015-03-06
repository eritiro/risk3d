/* Modificado por Mariano M. Chouza */
/* 
2d and 3d Vector C Library 
by Andrew Glassner
from "Graphics Gems", Academic Press, 1990
*/

#include <math.h>
#include <stdlib.h>
#include "math3d.h"

/* returns squared length of input vector */	
double V3SquaredLength(Vector3* a) 
{
	return((a->x * a->x)+(a->y * a->y)+(a->z * a->z));
}

/* returns length of input vector */
double V3Length(Vector3* a) 
{
	return(sqrt(V3SquaredLength(a)));
}

/* normalizes the input vector and returns it */
Vector3* V3Normalize(Vector3* v) 
{
	double len = V3Length(v);
	if (len != 0.0) { v->x /= len;  v->y /= len; v->z /= len; }
	return(v);
}

/* return the dot product of vectors a and b */
double V3Dot(Vector3* a, Vector3* b)
{
	return((a->x*b->x)+(a->y*b->y)+(a->z*b->z));
}

/* return the cross product c = a cross b */
Vector3* V3Cross(Vector3* a, Vector3* b, Vector3* c)
{
	c->x = (a->y*b->z) - (a->z*b->y);
	c->y = (a->z*b->x) - (a->x*b->z);
	c->z = (a->x*b->y) - (a->y*b->x);
	return(c);
}
