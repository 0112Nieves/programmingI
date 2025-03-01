#include "riemann.h"

int main()
{
	int32_t coefficients[1000] = {0};
	int32_t powers[1000] = {0};
	double a, b, n;
	int32_t size = 0;
	
	printf( "n: " );
	scanf( "%lf" , &n );
	printf( "a: " );
	scanf( "%lf" , &a );
	printf( "b: " );
	scanf( "%lf" , &b );
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
	
	printf( "sum: %lf\n" , riemann_sum( coefficients, powers, size, a, b, n ) );

	return 0;
}
