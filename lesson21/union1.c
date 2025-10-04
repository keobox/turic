#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Layout IIII or AAAA 4 bytes
   i and a share the same address
   refer to the same memory space
   in 2 different ways. */

struct foo {
    union {
        int i;
        unsigned char a[4];
    };
};

int main(void) {
    struct foo f;

    f.i = INT_MAX;
    printf("%d [%d %d %d %d]\n", f.i, f.a[0], f.a[1], f.a[2], f.a[3]);
    return 0;
}
