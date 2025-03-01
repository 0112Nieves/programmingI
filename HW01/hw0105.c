 #include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t num1 , num2 , num3 , num4 , num5;
    int32_t a , b , c , d , e , a1 , b1 , c1 , d1 , e1;
    int32_t tmp;
    char t;

	//input
    printf( "Please enter 5 cards: " );
    scanf( "%d%c%d%c%d%c%d%c%d", & num1 , &t , & num2 , &t , & num3 , &t , & num4 , &t , & num5 );

	//wronginput
	if( (num1 == num2) || (num1 == num3) || (num1 == num4) || (num1 == num5) || (num2 == num3) || (num2 == num4) || (num2 == num5) || (num3 == num4) || (num3 == num5) || (num4 == num5) )
	{
		printf( "Wrong Input!\n" );
	}
    else if( ( num1 || num2 || num3 || num4 || num5) < 1 || (num1 || num2 || num3 || num4 || num5) > 54 ){
        printf( "Wrong Input!\n" );
    }
    else{
    	
    	//求數字輸入後的牌號
    	a = num1 % 13;
    	b = num2 % 13;
    	c = num3 % 13;
    	d = num4 % 13;
    	e = num5 % 13;
    
    	//把餘0的變成13
    	if( a == 0 ){
    		a = 13;
    	}
    	if( b == 0 ){
    		b = 13;
    	}
    	if( c == 0 ){
    		c = 13;
    	}
    	if( d == 0 ){
    		d = 13;
    	}
    	if( e == 0 ){
    		e = 13;
    	}
    
    	//5個數排大小
    	if( a > b ){
    		tmp = a;
    		a = b;
    		b = tmp;
    	}
    	if( a > c ){
    		tmp = a;
    		a = c;
    		c = tmp;
    	}
    	if( a > d ){
    		tmp = a;
    		a = d;
    		d = tmp;
    	}
    	if( a > e ){
    		tmp = a;
    		a = e;
    		e = tmp;
    	}
    	if( b > c ){
    		tmp = b;
    		b = c;
    		c = tmp;
    	}
    	if( b > d ){
    		tmp = b;
    		b = d;
    		d = tmp;
    	}
    	if( b > e ){
    		tmp = b;
    		b = e;
    		e = tmp;
    	}
    	if( c > d ){
    		tmp = c;
    		c = d;
    		d = tmp;
    	}
    	if( c > e ){
    		tmp = c;
    		c = e;
    		e = tmp;
    	}
    	if( d > e ){
    		tmp = d;
    		d = e;
    		e = tmp;
    	}
    	
    	//排出9種類型
    	
    	//求花色
    	a1 = ((num1 - 1) / 13) + 1;
    	b1 = ((num2 - 1) / 13) + 1;
    	c1 = ((num3 - 1) / 13) + 1;
    	d1 = ((num4 - 1) / 13) + 1;
    	e1 = ((num5 - 1) / 13) + 1;
    
    	if((a == (b - 1) && a == (c - 2) && a == (d - 3) && a == (e - 4)) && (a1 == b1 && a1 == c1 && a1 == d1 && a1 == e1)) {
    		printf( "Straight flush\n" );
    	}
    	else if( (a == b && a == c && a == d) || (b == c && b == d && b == e) ){
    		printf( "Four of a kind\n" );
    	}
    	else if( ((a == b && a == c) && (d == e)) || ((a == b) && (c == d && c == e)) ){
    		printf( "Full house\n" );
    	}
    	else if( a1 == b1 && a1 == c1 && a1 == d1 && a1 == e1){
    		printf( "Flush\n" );
    	}
    	else if(a == (b - 1) && a == (c - 2) && a == (d - 3) && a == (e - 4)){
    		printf( "Straight\n");
    	}
    	else if((a == b && a == c) || (b == c && c == d) || (c == d && c == e)){
    		printf( "Three of a kind\n" );
    	}
    	else if(((a == b) && ((c == d) || (d == e))) || ((b == c) && (d == e))){
    		printf( "Two Pair\n" );
    	}
    	else if((a == b) || (b == c) || (c == d) || (d == e)){
    		printf( "One pair\n" );
    	} 
    	else{
    		printf( "High card\n" );
    	}   
    }
	return 0;
}
