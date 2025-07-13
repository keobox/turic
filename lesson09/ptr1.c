#include <stdio.h>

void incr(int *p) {
    *p = *p + 1;
}

int main(void) {
    int x = 5;
    int *y = NULL; // same as int *y=0
    printf("x was %d\n", x);
    y = &x;
    incr(y);
    printf("x is %d\n", x);
    return 0;
}
