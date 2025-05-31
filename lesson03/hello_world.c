#include <stdio.h>

int incr(int x) {
    x = x + 1;
    return x;
}

int main(void) {
    int a = 10;
    incr(a);
    /* prints 10 */
    printf("%d\n", a);
    return 0;
}
