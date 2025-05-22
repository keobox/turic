#include <stdio.h>

int sum(int a, int b) {
    /* a+b is an expression */
    return a+b;
}

int main(void) {
    /* warning in next line */
    printf("Hello World %d %d\n", sum(10, 20));
    return 0;
}
