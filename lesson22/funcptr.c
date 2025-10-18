#include <stdio.h>


int main (void) {
    int (*myf)(void);

    myf = main;

    printf("%p\n", main);
    printf("%p\n", myf);
    return 0;
}
