#include "hanoi.h"

int main() {
    int32_t n = 0;
    printf("Please enter the disk number (2-20): ");
    scanf("%d", &n);
    if( n < 2 || n > 20 ){
    	printf( "Error input!\n" );
    	return 0;
    }
    hanoi(n, '1', '3', '2');
    return 0;
} 
