#include <stdio.h>

int incr(int x) {
    x = x + 1;
    return x;
}

int main(void) {
    int a = 10;
    /* Use return values of a function.
       Now prints 11 */
    a = incr(a);
    printf("%d\n", a);
    return 0;
}
