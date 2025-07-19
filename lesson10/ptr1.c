#include <stdio.h>

void printstr(char *p) {
    while (*p != 0) {
        putchar(*p);
        p++;
    }
    printf("\n");
}

int main(void) {
    char mystr[] = "AABBCCDDEEFF";
    char *p =  mystr;
    printstr(p);
    printstr(mystr);
    return 0;
}
