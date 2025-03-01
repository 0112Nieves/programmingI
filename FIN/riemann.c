#include "riemann.h"
double f(double x, int32_t coefficients[], int32_t powers[], int32_t size);
double riemann_sum( int32_t coefficients[], int32_t powers[], int32_t size, double a, double b, int32_t n )
{
	double sum, x, function;
	
	for( int32_t i = 0 ; i <= n - 1 ; i++ ){
		x = a + ((b - a) / n) * i;
		function = f(x, coefficients, powers, size);
		sum += function * ((b - a) / n);
	}
	return sum;
}

double f(double x, int32_t coefficients[], int32_t powers[], int32_t size)
{
	double tmp = 1;
	for( int32_t i = 0 ; i < size ; i++ ){
		for( int32_t j = 0 ; j < coefficients[i] ; j++ ){
			tmp *= x;
		}
		tmp *= powers[i];
	}
	return tmp;
}
