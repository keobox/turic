#include <stdio.h>
#include <stdint.h>

struct pls {
    uint32_t len;
    uint32_t refcount;
    char str[0];
};
