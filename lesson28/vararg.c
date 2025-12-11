#include <stdio.h>
#include <stdarg.h>

void foo(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}

int main(void) {
    printf("Hello world\n");
    foo("%d %d %s %d", 10, 20, "ciao ciao", 5);
    return 0;
}
