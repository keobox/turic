#include <stdio.h>

int main(void) {
    char str[] = "Hello0000123";
    char *p = str;
    while(*p) {
        // putchar(*p);
        printf("%d ", *p);
        p++;
    }
    printf("\n");
    return 0;
}
