#include <stdio.h>

int main (void) {
    int i = 0;
    for (; ;) {
        if (i >= 10) break;
        printf("%d\n", i);
        i++;
    }
    return 0;
}
