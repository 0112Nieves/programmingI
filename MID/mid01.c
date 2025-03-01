#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

	
int main()
{
	double x1 = 0;
	double x2 = 0;
	double x3 = 0;
	double x4 = 0;
	double x = 0;
	double xc = 0;
	double y1 = 0;
	double y2 = 0;
	double y3 = 0;
	double y4 = 0;
	double y = 0;
	double yc = 0;
	char c = 0;
	double m1 = 0;
	double m2 = 0;
	double m3 = 0;
	double m4 = 0;
	double m = 0;
	double end = 0;
	double dist1 = 0;
	double dist2 = 0;
	double m14 = 0;
	double m12 = 0;
	double m34 = 0;
	double m23 = 0;
	
	printf( "P1(x,y): " );
	scanf( "%lf%c%lf" , &x1 , &c , &y1 );
	printf( "P2(x,y): " );
	scanf( "%lf%c%lf" , &x2 , &c , &y2 );
	printf( "P3(x,y): " );
	scanf( "%lf%c%lf" , &x3 , &c , &y3 );
	printf( "P4(x,y): " );
	scanf( "%lf%c%lf" , &x4 , &c , &y4 );
	printf( "P(x,y): " );
	scanf( "%lf%c%lf" , &x , &c , &y );
	
	m1 = (y1 - y2) / (x1 - x2);
	m2 = (y2 - y3) / (x2 - x3);
	m3 = (y3 - y4) / (x3 - x4);
	m4 = (y1 - y4) / (x1 - x4);
	//判錯
	if( m1 != m3 || m2 != m4 ){
		printf( "It's not a rectangle.\n" );
		return 0;
	}
	m14 = m1 * m4;
	m12 = m1 * m2;
	m34 = m3 * m4;
	m23 = m2 * m3;
	if( (m1 != 0 && m2 != 0 ) && (m14 != -1 || m12 != -1 || m34 != -1 || m23 != -1) ){
		printf( "It's not a rectangle.\n" );
		return 0;
	}
	dist1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	dist2 = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	if( dist1 == dist2 ){
		printf( "It's not a rectangle.\n" );
		return 0;
	}
	xc = abs(x1 - x2) / 2;
	yc = abs(y1 - y3) / 2;
	
	m = (yc - y) / (xc - x);
	end = -m * xc + yc;
	printf( "Line: y = %lf * x + %lf\n" , m , end );
	
	return 0;
}
