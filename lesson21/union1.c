#include <stdio.h>

/* Layout IIIIAAAA */

struct foo {
    int i;
    unsigned char a[4];
};

int main(void) {
    /* Possible initialization but not so used */
    struct foo f = {10, {1, 2, 3, 4}};
    
    printf("%d %d\n", f.i, f.a[2]);
    return 0;
}
