#include <stdio.h>
#include <string.h>

/* Layout IIIIAAAA 8 bytes */

struct foo {
    int i;
    unsigned char a[4];
};

int main(void) {
    struct foo f;

    f.i = 10;
    memcpy(f.a, "abcd", 4);
    printf("%d %d\n", f.i, f.a[2]);
    return 0;
}
