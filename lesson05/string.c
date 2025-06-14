#include <stdio.h>

int main(void) {
    char str[] = "hello";
    str[3] = 'X';
    printf("Hello world %s\n", str);
    return 0;
}
