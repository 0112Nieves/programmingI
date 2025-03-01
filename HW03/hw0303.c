#include "resistance.h"
#include <math.h>

int main(){
	double r = 0;
	int32_t n = 0;
	double ans = 0;
	
	printf( "Please enter the resistance (1-100): " );
	scanf( "%lf" , &r );
	if( r < 1 || r > 100 ){
		printf( "Error input!\n" );
		return 0;
	}
	printf( "Please enter n (1-100): " );
	scanf( "%d" , &n );
	if( n < 1 || n > 100 ){
		printf( "Error input!\n" );
		return 0;
	}
	ans = resistance( r , n );
	if( fabs( ans - (int32_t)ans ) < 1e-8 ){
		printf( "Ans: %d\n" , (int32_t)ans );
		return 0;
	}
	printf( "Ans: %lf\n" , ans );

	return 0;
}
