#include <stdio.h>
#include <stdlib.h>

/* The function returns NULL if there's no memory else it returns the fraction 'object' */
int *create_fraction(int num, int den) {
    int *f = malloc(sizeof(int)*2);
    // malloc error checking
    if (f == NULL) return NULL;
    f[0] = num;
    f[1] = den;
    return f;
}

void print_fraction(int *f) {
    printf("%d/%d\n", f[0], f[1]);
}

int main(void) {
    int *f1 = create_fraction(1, 2);
    int *f2 = create_fraction(3, 4);
    // Should check f1, f2 for NULL
    print_fraction(f1);
    print_fraction(f2);
    return 0;
}
