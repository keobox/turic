#include <stdio.h>

int main (void) {
    int i = 0;
    for (; ; i++) {
        if (i >= 10) break;
        printf("%d\n", i);
    }
    return 0;
}
