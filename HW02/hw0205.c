#include <stdio.h>
#include <stdint.h>

int main ()
{
	int32_t length = 0;
	int32_t width = 0;
	int32_t height = 0;
	int32_t amount = 0;
	
	printf( "Welcome to Cuboid Super Infinity Exporter!\n" );
	printf( "Please enter Length , Width , and Height of the cuboid\n" );
	printf( "Length:" );
	scanf( "%d" , &length );
	printf( "Width:" );
	scanf( "%d" , &width );
	printf( "Height:" );
	scanf( "%d" , &height );

	printf( "How many cuboids do you want to generate?\n" );
	printf( "Amount:" );
	scanf( "%d" , &amount );

	//error input
	if( length < 4 || width < 4 || height < 4){
		printf( "an error message\n" );
		return 0;
	}
	//first line
	/*for( int32_t k = 1 ; k <= amount ; k++ ){*/
		for( int32_t i = 1 ; i < width ; i++){
			printf( " " );
		}
		for( int32_t i = 0 ; i < 2 * length ; i++ ){
			printf( "#" );
		}
		printf( " " );
	printf( "\n" );
	//second line
	for(int32_t i = 0 ; i < width - 2 ; i++ ){
		printf( " " );
	}
	printf( "#" );
	for( int32_t i = 0 ; i < 2 * (length - 1) ; i++){
		printf( "\033[42m \033[0m" );
	}
	printf( "## " );
	printf( "\n" );
	//green
	for( int32_t i = 1 ; i < width - 2 ; i++ ){
		for( int32_t j = 1 ; j < width - i - 1 ; j++ ){
			printf( " " );
		}
		printf( "#" );
		for( int32_t j = 0 ; j < 2 * ( length - 1 ) ; j++ ){
			printf( "\033[42m \033[0m" );
		}
		printf( "#\n" );
	}

	//connection #
	for( int32_t i = 0 ; i < 2 * length ; i++){
		printf( "#" );
	}
	printf( " \n" );
	//blue
	for( int32_t i = 0 ; i < height - 2 ; i++ ){
		printf( "#" );
		for( int32_t j = 0 ; j < 2 * ( length - 1 ) ; j++ ){
			printf( "\033[44m \033[0m" );
		}
		printf( "# \n" );
	}
	for( int32_t i = 0 ; i < 2 * length ; i++){
		printf( "#" );
	}
	printf( "\n" );

	return 0;
}
