#include "brainfuck.h"
#include <stdio.h>
#include <stdint.h>

int32_t num6( int32_t code )
{
	int32_t sum6 = 0;
	if( code == 6 ){
		sum6++;
	}
	return sum6;
}

int32_t num7( int32_t code )
{
	int32_t sum7 = 0;
	if( code == 7 ){
		sum7++;
	}
	return sum7;
}	

void csie_interpreter(const uint8_t code[], size_t size, size_t mem_limit)
{
	int32_t *data_ptr;
	int32_t count6[size], count7[size];
	int32_t tmp = 0;
	int32_t now = 0;
	int32_t counter = 0;
	int32_t input = 0;
	int32_t j = 0;
	int32_t counter7 = 0;
	
	//count 6 and 7 number
	for( int32_t i = 0 ; i < size ; i++ ){
		if( code[i] == 6 ){
			count6[tmp] = i;
			tmp++;
		}
		if( code[i] == 7 ){
		tmp--;
		printf( "%d\n" , count6[tmp] );
		/*
			if( count6[tmp] != -1 ){
				count7[j] = count6[now];
				printf( "%d\n" , count6[now] );
				count6[tmp] = -1;
			}
			else{*/
				count7[j] = count6[tmp];
				count6[tmp] = -1;
			//}
			j++;
		}
	}
	
	/*for( int32_t i = 0 ; i < j ; i++ ){
		printf( "%d count6: %d , count7: %d\n" , i, count6[i], count7[i] );
	}*/
	/*
	printf( "tmp: %d\n" , tmp );
	printf( "now: %d\n" , now );
	for( int32_t i = 0 ; i < tmp ; i++ ){
		printf( "count7 i: %d ,%d\n" , i, count7[i] );
	}*/
			 
	while( counter < size ){
		switch( code[counter] )
		{
			case 0:
				++data_ptr;
				if( data_ptr >= (uint8_t *)mem_limit ){
					printf( "error!\n" );
					return;
				}
				break;
			case 1:
				--data_ptr;
				if( data_ptr < 0 ){
					printf( "error!\n" );
					return;
				}
				break;
			case 2:
				++ *data_ptr;
				break;
			case 3:
				-- *data_ptr;
				break;
			case 4:
				printf( "output: %d\n" , input );
				break;
			case 5:
				printf( "input: " );
				scanf( "%d" , &input );
				break;
			case 6:
				num6( *code );
				if( *data_ptr == 0 ){
					//counter = count7[num6]++;
				}
				break;
			case 7:
				num7( *code );
				if( *data_ptr != 0 ){
					counter = count7[counter7] + 1;
				}
				break;
			default:
				break;
		}
		counter++;
	}
	printf( "total: %d\n" , *data_ptr );
	return;
}
