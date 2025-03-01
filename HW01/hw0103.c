#include <stdio.h>
#include <stdint.h>
#include <string.h>
 
int main()
 
{
	int32_t Ax,Ay,Bx,By,Cx,Cy;
    double m1,m2,m3,k;
    char c;
    
    printf( "Please enter the point_A (x,y):" );
    scanf( "%d%c%d" , & Ax , &c , &Ay  );
    printf( "Please enter the point_B (x,y):" );
    scanf( "%d%c%d" , & Bx , &c , & By );
    printf( "Please enter the point_C (x,y):" );
    scanf( "%d%c%d" , & Cx , &c , & Cy );
    
    m1 = (float)(By - Ay) / (Bx - Ax);
    m2 = (float)(Cy - Ay) / (Cx - Ax);
    
    if( (Ax == Bx) && (Ay == By) )
    {
    printf( "Error\n" );
    }
    else
    { 
    	if(Ax == Bx)
    	{
        	printf( "The line : y="" %d\n", Cy );
    	}
    	else if(Ay == By)
    	{
        	printf( "The line : x ="" %d\n", Cx );
    	}
    	else
    	{
    		m3 = -1/((float)(By - Ay) / (Bx - Ax));
    		k = -m3*Cx + Cy;
        	printf( "The line : y = " "%6f" "x " , m3 );
        	
        	if( k >= 0 )
        	{
        	printf( "+"" %f\n" , k  );
        	}
        	else
        	{
        	printf( "%f\n" , k );
        	}
    	}
    }
    return 0;
}
