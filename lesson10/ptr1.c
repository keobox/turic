#include <stdio.h>

int main(void) {
    int x = 5;
    int *y = &x;
    printf("x is stored in %p and the value is %d\n", y, x);
    printf("x is stored in %p and the value is %d\n", &x, x);
    return 0;
}
