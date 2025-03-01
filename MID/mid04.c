#include <stdio.h>
#include <stdint.h>
int main()
{
	double r = 0;
	double t = 0;
	double speed = 0;
	double poss = 0;
	double possi = 0;
	double count = 0;
	int32_t i = 0;
	
	printf( "The Hare Speed (m/turn): " );
	scanf( "%lf" , &speed );
	printf( "The Nap Probability (0-1): " );
	scanf( "%lf" , &poss );
	
	while( count <= 13.2 ){
		printf( "Turn %d)" , i );
		i += 1;
		printf( " Tortoise: %f," , t );
		t += 0.300000;
		if( possi < 1 ){
			printf( " Hare: %f" , r );
			r += speed;
		}
		else{
			printf( " Hare: %f (NAP)" , r - speed );
			possi -= 1;
			r += speed;
		}
		possi += poss;
		if( r >= 13.2 ){
			printf( "(Winner)\n" );
		}
		else{
			printf( "\n" );
		}
		//判斷結束
		if( t - r > 0 ){
			count = t;
		}
		else{
			count = r;
		}
	}
	printf( "Turn %d)" , i );
	printf( " Tortoise: %f (Winner)" , t );
	if( possi < 1 ){
		printf( " Hare: %f\n" , r );
	}
	else{
		printf( " Hare: %f(NAP)\n" , r );
	}
	
	return 0;
}
