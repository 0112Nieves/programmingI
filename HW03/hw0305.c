#include "smallten.h"
#include "logic.h"
#include <stdint.h>
#include <math.h>

int main()
{
	int32_t first = 0;
	int32_t second = 0;
	int32_t sum1 = 0;
	int32_t sum2 = 0;
	int32_t count1 = 0;
	int32_t count2 = 0;
	int32_t tmp1 = 0;
	int32_t tmp2 = 0;
	int32_t sum = 0;
	int32_t sumend = 0;
	int32_t decimal1 = 0;
	int32_t decimal2 = 0;
	
	communicate();
	
	//input
	printf( "Please enter the first number (A) in binary:" );
	scanf( "%d" , &first );
	tmp1 = first; 
	//判錯
	if( first <= 0 ){
		printf( "Error\n" );
		return 0;
	}
	while( first != 0 ){
		sum1 = first % 10;
		first /= 10;
		if( sum1 != 0 && sum1 != 1 ){
			printf( "Error\n" );
			break;
			return 0;
		}
		count1 ++;
		if( count1 > 4 ){
			printf( "Error\n" );
			break;
			return 0;
		}
	}
	
	//input
	printf( "Please enter the second number (B) in binary:" );
	scanf( "%d" , &second );
	tmp2 = second;
	//判錯
	if( second <= 0 ){
		printf( "Error\n" );
		return 0;
	}
	while( second != 0 ){
		sum2 = second % 10;
		second /= 10;
		if( sum2 != 0 && sum2 != 1 ){
			printf( "Error\n" );
			break;
			return 0;
		}
		count2 ++;
		if( count2 > 4 ){
			printf( "Error\n" );
			break;
			return 0;
		}
	}
	int32_t tmp11 = tmp1;
	int32_t i = 0;
	while( tmp1 != 0 ){
		int32_t m = 0;
		m = tmp1 % 10;
		tmp1 /= 10;
		decimal1 += m * pow(2, i);
		i++;
	} 
	
	int32_t tmp21 = tmp2;
	int32_t j = 0;
	while( tmp2 != 0 ){
		int32_t m = 0;
		m = tmp2 % 10;
		tmp2 /= 10;
		decimal2 += m * pow(2, j);
		j++;
	}
	
	sum = decimal1 * decimal2;
	
	//output
	printf( "A = %04d (2) = %d (10)\n" , tmp11 , decimal1 );
	printf( "B = %04d (2) = %d (10)\n" , tmp21 , decimal2 );
	printf( "A x B = %d * %d = " , decimal1 , decimal2 );
	int32_t m = 0;
	int32_t c = 0;
	int32_t k = 0;
	int32_t n = 2;
	int32_t arr[k];
	sumend = sum;
	while( sum > 0 ){
		c = sum % n;
		arr[k] = c;
		sum = sum / n;
		k++;
	}
	if( k == 1 ){
		printf( "0000000" );
	}
	if( k == 2 ){
		printf( "000000" );
	}
	if( k == 3 ){
		printf( "00000" );
	}
	if( k == 4 ){
		printf( "0000" );
	}
	if( k == 5 ){
		printf( "000" );
	}
	if( k == 6 ){
		printf( "00" );
	}
	if( k == 7 ){
		printf( "0" );
	}
	for( k-- ; k >= 0 ; k -- ){
		printf( "%d" , arr[k] );
	}	
	printf( " (2) = " );
	printf( "%d (10)\n" , sumend );
	return 0;
}
