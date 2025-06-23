#include <stdio.h>

int main(void) {
    int i = 8;
    {
        int i = 5;
        printf("i is %d\n", i);
        // inner i scope finishes here
    }
    // outer block i is visible here
    printf("i is %d\n", i);
    return 0;
}
