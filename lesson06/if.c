#include <stdio.h>

int main(void) {
    int i = 8;
    {
        int i = 5;
        printf("i is stored at %p\n", &i);
    }
    printf("i is stored at %p\n", &i);
    return 0;
}
