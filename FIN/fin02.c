#include "canvas.h"
#include <stdio.h>
#include <stdint.h>

int32_t color( int32_t input, int32_t x, int32_t y );

int main()
{	
	int32_t x, y;
	int32_t input;
	char c;
	for( int32_t i = 0 ; i < row_size ; i ++ ){
		for( int32_t j = 0  ;j < col_size ; j++ ){
			if( canvas[i][j] == 1 ){
				printf( "\e[0;40m  \e[0m" );
			}
			printf( "\e[0;47m  \e[0m" );
		}
		printf( "\n" );
	}
	
	for( int32_t i = 0 ; i < row_size ; i ++ ){
		for( int32_t j = 0  ;j < col_size ; j++ ){
			printf( "Please enter the point(x,y): " );
			scanf( "%c%d%c%d%c" , &c, &x, &c, &y, &c );
			printf( "Please enter the color[0-4]: " );
			scanf( "%d" , &input );
			if( canvas[x][y] == 1 ){
				printf( "warning\n" );
			}
			color( input, i, j );
			switch(input){
				case 0:
					printf( "\e[0;47m  \e[0m" );
					break;
				case 1:
					printf( "\e[0;41m  \e[0m" );
					break;
				case 2:
					printf( "\e[0;43m  \e[0m" );
					break;
				case 3:
					printf( "\e[0;42m  \e[0m" );
					break;
				case 4:
					printf( "\e[0;44m  \e[0m" );
					break;
			}
			printf( "\n" );
		}
	}	
	return 0;
}	
int32_t color( int32_t input, int32_t x, int32_t y )
{
	int32_t color_change[100][100];
	//stop
	if( canvas[x-1][y] == 1 )
		return 0;
	if( canvas[x+1][y] == 1 )
		return 0;
	if( canvas[x][y-1] == 1 )
		return 0;
	if( canvas[x][y+1] == 1 )
		return 0;
	//color
	if( canvas[x-1][y] == 0 )
		color_change[x-1][y] = input;
	if( canvas[x+1][y] == 0 )
		color_change[x+1][y] = input;
	if( canvas[x][y-1] = 0 )
		color_change[x][y-1] = input;
	if( canvas[x][y+1] = 0 )
		color_change[x][y+1] = input;	
}
