#include <stdio.h>

int main(void) {
    char str[] = {1, 1, 2, 2};
    short* s = (short*) str;
    printf("Dec %d\t%d\n", s[0], s[1]);
    printf("Hex %x\t%x\n", s[0], s[1]);
    return 0;
}
