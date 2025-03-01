#include "myfunc.h"

int main()
{
	int32_t coefficients[1000] = {0};
	int32_t powers[1000] = {0};
	double a = 0;
	int32_t n = 0;
	int32_t size = 0;
	
	printf( "n: " );
	scanf( "%d" , &n );
	printf( "a: " );
	scanf( "%lf" , &a );
	printf( "size: " );
	scanf( "%d" , &size );
	printf( "coefficients: " );
	for( int32_t i = 0 ; i < size ; i++ ){
		scanf( "%d" , &(coefficients[i]) );
	}
	printf( "powers: " );
	for( int32_t i = 0 ; i < size ; i++ ){
		scanf( "%d" , &(powers[i]) );
	}
	
	printf( "sum: %lf\n" , cal_n_derivatives( n, a, size, coefficients,  powers ) );
	
	return 0;
}
