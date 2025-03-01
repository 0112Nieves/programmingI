#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
	int32_t num1,num11,num12,num13,num2,num21,num22,num23,sum,sum1,sum2,sum3 = 0;
	
    printf("Please enter first number:");
	scanf( "%d", &num1 );

	printf("Please enter second number:");
	scanf( "%d", &num2 );

	if( (num1 < 100 || num1 > 1000 ) || ( num2 < 100 || num2 > 1000))
	{
		printf( "an error message\n" );
	}
	else
	{
		sum = num1 - num2;
		num11 = (num1 / 100);
		num1 = num1 - num11 * 100;
		num12 = (num1 / 10);
		num13 = num1 - num12 * 10;
		num21 = (num2 / 100);
		num2 = num2 - num21 * 100;
		num22 = (num2 / 10);
		num23 = num2 - num22 * 10;
		printf( "   %d", num11 );
		printf( " %d", num12 );
		printf( " %d\n", num13 );
		printf( "-)"" %d", num21 );
		printf( " %d", num22 );
		printf( " %d\n", num23 );
		printf( " --------\n" );
		
		if(sum>=0)
		{	
			sum1 = (sum / 100);
			sum = sum - sum1 * 100;
			sum2 = (sum / 10);
			sum3 = sum - sum2 * 10;
			if(sum1 == 0)
			{
				if(sum2 == 0)
				{
				printf(  "%8d\n" ,sum3);
				}
				else
				{
				printf(  "%6d%2d\n" , sum2,sum3);
				}
			}
			else 	
			{
			printf( "%4d%2d%2d\n", sum1,sum2,sum3 );
			}
		}
		
		if(sum<0)
		{	sum1 = (-sum / 100);
			sum = -sum - sum1 * 100;
			sum2 = (sum / 10);
			sum3 = sum - sum2 * 10;
			sum = -sum;
			if(sum1 == 0)
			{
			if(sum2 == 0)
				{
				printf(  "     -""%2d\n" ,sum3);
				}
				else
				{
				printf( "   -" "%2d%2d\n" , sum2,sum3);
				}
			}
			else 	
			{
				printf( "  -" "%d%2d%2d\n", sum1,sum2,sum3 );
			}
		}
	}	
	return 0;
}
