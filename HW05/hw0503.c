#include <stdio.h>
#include <stdint.h>

int32_t start( int32_t input );
int32_t s1( int32_t input );
int32_t s2( int32_t input );
int32_t s3( int32_t input );
int32_t s4( int32_t input );
int32_t s5( int32_t input );
int32_t s6( int32_t input );
int32_t final( int32_t input );
int32_t (*func[8])(int32_t);

int main()
{
	int32_t input, next = 0;
	func[0] = start; 
	func[1] = s1;
	func[2] = s2;
	func[3] = s3;
	func[4] = s4;
	func[5] = s5;
	func[6] = s6;
	func[7] = final;
	
	printf( "Start\n" );
	while(1){
		printf( "Please enter an integer: " );
		scanf( "%d" , &input );
		next = func[next]( input );
	}
	return 0;
}

int32_t start( int32_t input )
{
	if( input == 11 ){
		printf( "S3\n" );
		return 3;
	}
	if( input == 10 || input == 35 ){
		printf( "S1\n" );
		return 1;
	}
	if( input == 20 || input == 78 ){
		printf( "S5\n" );
		return 5;
	}
	printf( "Start\n" );
	return 0;
}

int32_t s1( int32_t input )
{
	if( input == 19 ){
		printf( "S2\n" );
		return 2;
	}
	if( input == 12 || input == 36 ){
		printf( "S6\n" );
		return 6;
	}
	printf( "S1\n" );
	return 1;
}

int32_t s2( int32_t input )
{
	if( input == 43 ){
		printf( "S2\n" );
		return 2;
	}
	if( input == 99 ){
		printf( "Final\n" );
		return 7;
	}
	printf( "Start\n" );
	return 0;
}

int32_t s3( int32_t input )
{
	printf( "S4\n" );
	return 4;
}

int32_t s4( int32_t input )
{
	printf( "S6\n" );
	return 6;
}

int32_t s5( int32_t input )
{
	if( input == 1 ){
		printf( "S4\n" );
		return 4;
	}
	if( input == 2 ){
		printf( "S6\n" );
		return 6;
	}
	printf( "Start\n" );
	return 0;
}

int32_t s6( int32_t input )
{
	if( input == 108 ){
		printf( "Final\n" );
		return 7;
	}
	printf( "S5\n" );
	return 5;
}

int32_t final( int32_t input )
{
	printf( "Final\n" );
	return 7;
}
