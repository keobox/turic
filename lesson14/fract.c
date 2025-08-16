#include <stdio.h>
#include <stdlib.h>

struct fract {
    int num;
    int den;
};

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

/* Semplify the fraction */
void semplify_fraction(int *f) {
    for (int d = 2; d <= f[0] && d <= f[1]; d++) {
        while (f[0] % d == 0 &&
               f[1] % d == 0) {
            f[0] /= d;
            f[1] /= d;
        }
    }
}

int main(void) {
    printf("%d\n", (int) sizeof(struct fract));

    struct fract a;
    struct fract *b;
    b = &a;
    b->num = 1;
    b->den = 2;
    printf("%d/%d\n", a.num, a.den);

#if 0
    int *f1 = create_fraction(10, 20);
    int *f2 = create_fraction(3, 4);
    // Should check f1, f2 for NULL
    semplify_fraction(f1);
    print_fraction(f1);
    print_fraction(f2);
#endif
    return 0;
}
