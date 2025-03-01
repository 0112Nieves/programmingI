#include "myfunc.h"
#include <stdio.h>

int main()
{ 
	double a = 0;
	double b = 0;
	double c = 0;
	double x = 0;
	char r = 0;
	double m = 0;
	double n = 0;

	printf( "Please enter a , b , c : ");
	scanf( "%lf%c%lf%c%lf" , &a , &r , &b , &r , &c );
	setup(a,b,c);
	//算最大值
	printf( "Please enter m , n: ");
	scanf( "%lf%c%lf" , &m , &r , &n );
	printf( "%lf\n" , max(m,n) );
	
	return 0;
}
