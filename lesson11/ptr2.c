#include <stdio.h>

int main(void) {
    // \017 in octal is 15 the original string length
    char str[] = "\017Hello00\0000000123";
    char *p = str;
    int len = *p; 
    printf("strlen %d\n", len);
    for (int j = 1; j <= len; j++) {
        putchar(p[j]);
    }
    printf("\n");
    return 0;
}
