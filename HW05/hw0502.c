#include <stdio.h>
#include <stdint.h>
#include "mymemcmp.h"
#include <string.h>

int main() {
    char buffer1[] = "abcde";
    char buffer2[] = "abcde";
    
    int ret = mymemcmp(buffer1, buffer2, sizeof(buffer1));
    if (ret > 0) {
        printf("buffer1 is greater than buffer2\n");
    } else if (ret < 0) {
        printf("buffer1 is less than buffer2\n");
    } else { // ret == 0
        printf("buffer1 is equal to buffer2\n");
    }

    return 0;
}
