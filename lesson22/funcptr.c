#include <stdio.h>

void hello(void) {
    printf("hello!\n");
}

void baubau(void) {
    printf("baubau!\n");
}

int main (void) {
    void (*x)(void);

    x = hello;
    x();

    x = baubau;
    x();

    return 0;
}
