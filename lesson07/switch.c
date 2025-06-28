#include <stdio.h>

int main (void) {
    int i = 5;

    switch(i) {
        case 5:
        {
            // declare a block for scoped variable
            int j = 0;
            printf("Is a five\n");
            printf("It's really a five\n");
            printf("j=%d\n", j);
            break;
        }
        case 7:
            printf("Is a seven\n");
            break;
        default:
            printf("Is another number\n");
            break;
    }

    printf("\n");
    // is equivalent to if
    if (i == 5) {
        printf("Is a five\n");
        printf("It's really a five\n");
    } else if (i == 7) {
        printf("Is a seven\n");
    } else {
        printf("Is another number\n");
    }
    return 0;
}
