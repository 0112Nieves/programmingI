#include "rotate.h"
#include <math.h>
#define PI acos(-1)

void rotate( double *x, double *y, double theta )
{	
	double cox = *x;
	double coy = *y;
	double angle = 0;
	
	angle = theta * PI / 180;
	
	*x = cox * (cos(angle)) - coy * (sin(angle));
	*y = coy * (cos(angle)) + cox * (sin(angle));

	return;
}
