#include <stdio.h>

int main(void) {
    int x = 5;
    int *y = NULL; // same as int *y=0
    printf("%d\n", x);
    y = &x;
    printf("x is stored at the address: %p\n", y);
    return 0;
}
