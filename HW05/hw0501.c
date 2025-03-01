#include <stdio.h>
#include <stdint.h>
#include "rotate.h"

void rotate( double *x, double *y, double thate );

int main()
{
	double x, y, theta;
	printf( "x: " );
	scanf( "%lf" , &x );
	printf( "y: " );
	scanf( "%lf" , &y );
	printf( "theta: " );
	scanf( "%lf" , &theta );
	rotate( &x, &y, theta );
	printf( "x: %lf, y: %lf\n" , x, y );

	return 0;
}
