#include <stdio.h>

int main (void) {
    int a[] = {1, 5, 8, 4, 9, 0};
    int i;
    for (i = 0; a[i] != 0; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
