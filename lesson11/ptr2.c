#include <stdio.h>

int main(void) {
    char str[] = "Hello\000000123";
    char *p = str;
    while(*p) {
        putchar(*p);
        p++;
    }
    printf("\n");
    return 0;
}
