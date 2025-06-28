#include <stdio.h>

int main (void) {
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    return 0;
}
