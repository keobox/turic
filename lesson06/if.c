#include <stdio.h>

int main(void) {
    int i = 8;
    {
        int i = 5;
        printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
    }
    printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
    return 0;
}
