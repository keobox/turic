#include <stdio.h>

int main(void) {
    int x = 5;
    int *y = NULL; // same as int *y=0
    printf("x was %d\n", x);
    y = &x;
    printf("x is stored at the address: %p\n", y);
    // *y = 10;
    y[0] = 10;
    printf("x is %d\n", x);
    return 0;
}
