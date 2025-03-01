#include "division.h"
#include <stdint.h>
#include <stdio.h>

/*void div(int a[100], int b[100], int c[100])
{
	int t[100];

	for (int i=100-1; i>=0; i--)
		for (int k=9; k>0; k--)	// 嘗試商數
		{
			mul(b+i, k, t);
			if (!less_than(a+i, t))
			{
				sub(a+i, t, c+i);
				break;
			}
		}
}

void mul(int a[100], int b[100], int c[100])
{
	for (int i=0; i<100; i++)
		c[i] = 0;

	for (int i=0; i<100; i++)
		for (int j=0; j<100; j++)
			if (i+j < 100)
				c[i+j] += a[i] * b[j];

	for (int i=0; i<100-1; i++)	// 一口氣進位
	{
		c[i+1] += c[i] / 10;
		c[i] %= 10;
	}
}

void sub( int32_t *pX , int32_t *pY, int32_t  )
{
	for (int i=0; i<100; i++)
		c[i] = a[i] - b[i];

	for (int i=0; i<100-1; i++)	// 一口氣借位和補位
		if (c[i] < 0)
		{
			c[i+1]--;			// 借位
			c[i] += 10;			// 補位
		}
}

// a < b
bool less_than(int32_t *pX, int32_t *pY)
{
	// 從高位數開始比，對應的位數相比較。
	for (int32_t i=-1; i>=0; i--)
		if (a[i] != b[i])	// 一旦ab不一樣大，馬上回傳結果。
			return a[i] < b[i];
	return false;	// 完全相等
}

int32_t compare( uint8_t *pX, uint8_t *pY )
{
	if( *pX >= pY ){
		return 0;
	}
	else{
		*pX++;
	}
}

void big_sub( uint8_t *pX, uint8_t *pY, uint8_t **ppRemainder, uint8_t xSize )
{
	//count
	int32_t bit = 0;
	pX[]-= bit;

	if( *pX < pY ){
		*pX += 10;
		bit = 1;
	}
	else{
		bit = 0;
	}
	**ppRemainder = *pX - pY;
}*/

void division( uint8_t **ppQuotient , uint8_t *pQuotientSize , uint8_t **ppRemainder , uint8_t *pRemainderSize , uint8_t *pX, uint8_t xSize , uint8_t *pY, uint8_t ySize )
{
	//除0
	/*if( ySize == 1 && pY == 0 ){
		return;
	}
	for( int32_t i = 0 ; i < xSize - ySize + 1 ; i++ ){
		printf( "test\n" );
		compare( pX, pY );
		big_sub( pX, pY, ppRemainder, xSize );
	}*/
	return;
}

int32_t buffer = 1; //k * pY
void big_mul( uint8_t *pX, uint8_t *pY, uint8_t **ppQuotient );
void big_sub( uint8_t *pX, uint8_t *pY, uint8_t **ppRemainder, uint8_t xSize );

void division( uint8_t **ppQuotient , uint8_t *pQuotientSize , uint8_t **ppRemainder , uint8_t *pRemainderSize , uint8_t *pX, uint8_t xSize , uint8_t *pY, uint8_t ySize )
{
printf( "division: main\n" );
	//除0
	if( ySize == 1 && pY == 0 ){
		return;
	}
	for( int32_t i = 0 ; i < xSize - ySize + 1 ; i++ ){
		printf( "test\n" );
		big_mul( pX, pY, ppQuotient );
		big_sub( pX, pY, ppRemainder, xSize );
	}
	return;
}

//guess quotient number
void big_mul( uint8_t *pX, uint8_t *pY, uint8_t **ppQuotient )
{
printf( "big_mul: main\n" );
	for( int32_t i = 0 ; i < 10 ; i++ ){
		buffer = i * (pY[i]);
		if( buffer >= pX[i] ){
			**ppQuotient = i;
			break;
		}
		**ppQuotient = 9;
	}
}

//count remainder number
void big_sub( uint8_t *pX, uint8_t *pY, uint8_t **ppRemainder, uint8_t xSize ) //x - y * n = r
{
printf( "big_sub: main\n" );
	//count
	int32_t bit = 0;
	pX[]-= bit;

	if( *pX < buffer ){
		*pX += 10;
		bit = 1;
	}
	else{
		bit = 0;
	}
	**ppRemainder = *pX - (buffer);
}
