#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pls {
    long len;
    char *str;
};

void hexdump(void *p, size_t len) {
   unsigned char *byte = p;
   for (size_t j = 0; j < len; j++) {
       printf("%02X ", byte[j]);
   }
   printf("\n");
}

int main(void) {
    struct pls s;
    s.len = 10;
    s.str = malloc(10+1);
    memcpy(s.str, "1234567890", 11);
    printf("%p\n", s.str);
    hexdump(&s, sizeof(s));
    return 0;
}
