#include <stdio.h>

typedef struct {
    int n;
    int d;
} fract;

int main(void) {
    fract f;
    f.n = 10;
    f.d = 20;
    printf("%d/%d\n", f.n, f.d);
    return 0;
}
