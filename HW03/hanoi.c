#include <stdio.h>
#include <stdint.h>

void hanoi(int n, char A, char B, char C) {
    if (n == 1){
        printf("move disk %d to rod %c\n" , n , C);
    }
    else{
    		//		from,temp,to
        hanoi(n - 1, A , C , B);
        printf("move disk %d to rod %c\n" , n , C);
        hanoi(n - 1, B , A , C);
    }
}
