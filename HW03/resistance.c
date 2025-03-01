#include <stdio.h>
#include <stdint.h>
#include "resistance.h"

static double R = 0;

double resistance( double r , int32_t n )
{
	if( R == 0 ){
		R = r;
	}
	if( n == 1 ){
		return R + r;
	}
	return resistance((r + R) * R / (r + 2 * R) , n - 1);
} 
