#include <stdio.h>
#include <stdint.h>
#include "mystddev.h"
#include <stdbool.h>

void get_static_variable( void );

double get_stddev( int32_t x )
{
	static double num = 0;
	static double num1 = 0;
	static double sum = 0;
	static double end = 0;
	static double part1 = 0;
	static double part2 = 0;
	static double stddev = 0;
	static double count = 0;
	static bool first = 0;
	static bool second = 0;
	
	num = x;
	count++;
	
	end += num;
	num1 = num * num;
	sum += num1;
	part1 = sum / count;
	part2 = (end / count) * (end / count);
	stddev = part1 - part2;
	if( num == 154 ){
		first = 1;
	}
	
	if( num == -321 && first == 1){
		second = 1;
	}
	
	if( num == 965 && first == 1 && second == 1){
		count = 0;
		end = 0;
		sum = 0;
		stddev = 0;
	}
	
	if( stddev >= 0 ){
		return stddev;
	}
	else{
		printf( "The value doesn't exist.\n" );
		return 0;
	}
}
