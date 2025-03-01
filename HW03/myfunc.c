#include <stdio.h>
#include <stdint.h>
#include "myfunc.h"
#include <math.h>

static int32_t a = 0;
static int32_t b = 0;
static int32_t c = 0;

int32_t setup( int32_t a1, int32_t b1, int32_t c1)
{
	a = a1;
	b = b1;
	c = c1;
	if( a1 == 0 ){
		return -1;
	}
	return 0;
}

double value( double x )
{	
	double value = 0;
	value = a * x * x + b * x + c;
	return value;
}

double min( double m, double n )
{
	double num = 0;
	double min = 0;
	num = ((-1) * b) / (2 * a);
	if( m == n ){
		printf( "The minimum doesn't exist\n" );
		return 0;
	}
	if( a > 0 ){
		if( (num > m && num < n) || (num < m && num > n) ){
			min = 0;
		}
		else if( m > n && m > num && n > num ){
			min = a * n * n + b * n + c;
		}
		else if( m > n && m < num && n < num ){
			min = a * m * m + b * m + c;
		}
		else if( n > m && n > num && m > num ){
			min = a * m * m + b * m + c;
		}
		else{
			min = a * n * n + b * n + c;
		}
	}
	if( a < 0 ){
		if( m > n && m - num < 0 ){
			min = a * n * n + b * n + c;
		}
		else if( m > n && n - num > 0 ){
			min = a * m * m + b * m + c;
		}
		else if( n > m && n - num < 0 ){
			min = a * m * m + b * m + c;
		}
		else{
			min = a * n * n + b * n + c;
		}
	}
	return min;
}

double max( double m, double n )
{
	double num = 0;
	double max = 0;
	num = ((-1) * b) / (2 * a);
	if( m == n ){
		printf( "The maximum doesn't exist\n" );
		return 0;
	}
	if( a > 0 ){
		if( m > n && n > num ){
			max = a * m * m + b * m + c;
		}
		else if( m > n && m < num ){
			max = a * n * n + b * n + c;
		}
		else if( m < n && m > num ){
			max = a * n * n + b * n + c;
		}
		else{
			max = a * m * m + b * m + c;
		}
	}
	
	if( a < 0 ){
		if( (num > m && num < n) || (num < m && num > n) ){
			max = a * num * num + b * num + c;
		}
		else if( m > n && n > num ){
			max = a * n * n + b * n + c;
		}
		else if( m > n && m < num ){
			max = a * m * m + b * m + c;
		}
		else if( m < n && m > num ){
			max = a * m * m + b * m + c;
		}
		else{
			max = a * n * n + b * n + c;
		}
	} 
	return max;
}

double slope( double t )
{
	double slope = 0;
	slope = 2 * a * t + b;
    return slope;
}
