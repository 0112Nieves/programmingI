#include "mystddev.h"
int main()
{
	int32_t num = 0;
	for( int32_t i ; i < 5 ; i++ ){
		printf( "Please enter a number :" );
		scanf( "%d" , &num );
		printf( "%f\n" , get_stddev(num) );
	}
	return 0;
}
