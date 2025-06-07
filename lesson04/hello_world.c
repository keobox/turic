#include <stdio.h>

void clear(void) {
    printf("\x1b[H");
}

int main(void) {
    clear();
    printf("Hello World\n");
    return 0;
}
