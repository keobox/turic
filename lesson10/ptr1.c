#include <stdio.h>

int main(void) {
    char mystr[] = "AABBCCDDEEFF";
    char *p =  mystr;
    printf("At the beginning p is %p\n", p);
    while (*p != 0) {
        putchar(*p);
        p++;
    }
    printf("\n");
    printf("At the end p is %p\n", p);
    return 0;
}
