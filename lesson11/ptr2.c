#include <stdio.h>

int main(void) {
    char str[] = "aabb";
    short* s = (short*) str;
    // 'a' = 0x61, 'b' = 0x62
    printf("Str %c%c\t\t%c%c\n", str[0], str[1], str[2], str[3]);
    printf("Dec %d\t%d\n", s[0], s[1]);
    printf("Hex %x\t%x\n", s[0], s[1]);
    return 0;
}
