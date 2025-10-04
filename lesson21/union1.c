#include <stdio.h>
#include <string.h>
#include <limits.h>

/* These field should cost just 2 bytes
   because the number after ':' is the number
   of bits of the fields = 16 bits = 2 bytes */

struct foo {
    unsigned char a:4;
    unsigned char b:4;
    unsigned char c:8;
};

int main(void) {
    struct foo f;
    printf("%zu\n", sizeof(f));
    return 0;
}
