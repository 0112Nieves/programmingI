#include <stdio.h>
#include <stdint.h>
#include "myfunc.h"
#include <math.h>

double cal_n_derivatives( int32_t n, double a, int32_t size, int32_t coefficients[], int32_t powers[] )
{	
	double sum = 0;
	
	//微幾次
	for( int32_t i = 0 ; i < n ; i++ ){
		//有幾個數
		for( int32_t j = 0 ; j < size ; j++ ){
			coefficients[j] *= powers[j];
			powers[j] -= 1;
		}
	} 
	for( int32_t i = 0 ; i < size ; i++ ){
		sum += pow( a, powers[i] ) * coefficients[i];
	}
	
	return sum;
}
