#include <stdio.h>
#include <stdlib.h>

struct fract {
    int num;
    int den;
};

/* The function returns NULL if there's no memory else it returns the fraction 'object' */
struct fract *create_fraction(int num, int den) {
    // struct fract *f = malloc(sizeof(struct fract));
    // below line is equal to above line
    struct fract *f = malloc(sizeof(*f));
    // malloc error checking
    if (f == NULL) return NULL;
    f->num = num;
    f->den = den;
    return f;
}

void print_fraction(struct fract *f) {
    printf("%d/%d\n", f->num, f->den);
}

/* Semplify the fraction */
void semplify_fraction(struct fract *f) {
    for (int d = 2; d <= f->num && d <= f->den; d++) {
        while (f->num % d == 0 &&
               f->den % d == 0) {
            f->num /= d;
            f->den /= d;
        }
    }
}

int main(void) {
    struct fract *f1 = create_fraction(10, 20);
    struct fract *f2 = create_fraction(3, 4);
    // Should check f1, f2 for NULL
    semplify_fraction(f1);
    print_fraction(f1);
    print_fraction(f2);
    return 0;
}
