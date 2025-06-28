#include <stdio.h>

int main (void) {
    int a[] = {1, 5, 8, 4, 9, 0};
    int i;
    for (i = 0; a[i] != 0; i++) {
        if (a[i] == 8) break;
    }
    if (a[i] == 0) {
        printf("Not found\n");
    } else {
        printf("found\n");
    }
    return 0;
}
