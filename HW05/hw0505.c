#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int s;
    uint8_t *c;
    int memlimit;
    printf("how many code?");
    scanf("%d", &s);
    printf("code:\n");
    c = calloc(s, sizeof(uint8_t));
    for (int i = 0; i < s; ++i) {
        scanf("%hhu", &c[i]);
    }
    printf("memory limit\n");
    scanf("%d", &memlimit);
    csie_interpreter(c, s, memlimit);
    free(c);
}
