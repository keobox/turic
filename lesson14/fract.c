#include <stdio.h>
#include <stdlib.h>

void set_fraction(int *f, int num, int dem) {
    f[0] = num;
    f[1] = dem;
}

void print_fraction(int *f) {
    printf("%d/%d\n", f[0], f[1]);
}

int main(void) {
    int *f = malloc(sizeof(int)*2);
    set_fraction(f, 1, 2);
    print_fraction(f);
    return 0;
}
