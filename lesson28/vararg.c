#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void foo(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    char mybuf[32];
    vsnprintf(mybuf, sizeof(mybuf), fmt, ap);
    for (int j = 0; j < sizeof(mybuf); j++) {
        mybuf[j] = tolower(mybuf[j]);
    }

    printf("%s\n", mybuf);
    va_end(ap);
}

int main(void) {
    printf("Hello world\n");
    foo("Hi Hi hi AAAABBB %d %d %s", 10, 20, "CIAO");
    return 0;
}
