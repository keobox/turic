#include <stdio.h>
#include <assert.h>

/* Want to check if the whole struct is packed
   into 32 bits after looking at redisObject
   and if "unsigned" defaults to "unsigned int" */

struct bar {
    unsigned a:8;
    unsigned b:8;
    unsigned c:8;
    unsigned d:8;
};

int main(void) {
    struct bar baz;

    baz.a = 1;
    baz.b = 2;
    baz.c = 3;
    baz.d = 4;
    assert(sizeof(baz) == 4);
    printf("%zu\n", sizeof(baz));
    printf("%d %d %d %d\n", baz.a, baz.b, baz.c, baz.d);
    return 0;
}
