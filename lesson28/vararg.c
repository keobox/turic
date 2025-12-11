#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

void foo(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    char mybuf[32];
    vsnprintf(mybuf, sizeof(mybuf), fmt, ap);
    size_t len = strlen(mybuf);
    /* centered string */
    size_t padding = (80 - len)/2;
    for (size_t j = 0; j < padding; j++) printf(" ");
    printf("%s\n", mybuf);
    va_end(ap);
}

int main(void) {
    printf("Hello world\n");
    foo("Hi Hi hi AAAABBB %d %d %s", 10, 20, "CIAO");
    return 0;
}
