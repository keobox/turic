#include <stdio.h>

int main(void) {
    int i = 0;

// Next line is a "label" and starts with a letter
again:
    printf("%d\n", i);
    i++;
    if (i < 10) goto again;

    printf("\n");
    i = 0;
    while(i < 10) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}
