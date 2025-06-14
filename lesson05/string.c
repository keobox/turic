#include <stdio.h>

int main(void) {
    char str[6] = {'h', 'e', 'l','l', 'o', 0};
    char str2[6] = "hello";
    printf("Hello world %s %s\n", str, str2);
    return 0;
}
