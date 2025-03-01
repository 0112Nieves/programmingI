#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	int32_t n = 0;
	int32_t var = 0;
	double GD = 0;
	double ND = 0; 
	double GLS = 0;
	double NS = 0;
	double GLSsen = 0;
	double NSsen = 0;
	
	printf( "Please enter n (16-bits unsigned): " );
	scanf( "%d" , &n);
	
	//error input
	if( n > 65535 ){
		printf( "n is over 16-bits unsigned\n" );
	}
	
	//n = 1出現
	if( n >= 1 ){
		printf( "n = 1:\n" );
		GLS = 4;
		NS = 3;
		GD = fabs( 3.14159265358979323846 - GLS );
		ND = fabs( 3.14159265358979323846 - NS );
		printf( "	Gregory – Leibniz series: 4.000000(0.8584073)\n" );
		printf( "	Nilakantha series: 3.000000(0.1415927)\n" );
	}
		
	//n > 1出現
	GLS = 4;
	NS = 3;
	for( int32_t i = 2 ; i <= n ; i++ ){
		printf( "n = %d:\n" , i );
		//每一小格算式
		var = i;
		GLSsen = (pow(-1 , var + 1) * 4) / (2 * var - 1);
		NSsen = (pow(-1 , var ) * 4) / ((2 * var - 2) * (2 * var - 1) * (2 * var));
		//加回數字運算
		GLS += GLSsen;
		NS += NSsen;
		//算差值
		GD = fabs( 3.14159265358979323846 - GLS );
		ND = fabs( 3.14159265358979323846 - NS );
		printf( "	Gregory – Leibniz series: %f(%f)\n" , GLS , GD );
		printf( "	Nilakantha series: %f(%f)\n" , NS , ND );
		GLSsen = 0;
		NSsen = 0;
		var = 0;
	}

	return 0;
}
