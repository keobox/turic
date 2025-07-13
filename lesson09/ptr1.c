#include <stdio.h>

void incr(int *p) {
    *p = *p + 1;
}

int main(void) {
    int x = 5;
    printf("x was %d\n", x);
    incr(&x);
    printf("x is %d\n", x);
    return 0;
}
