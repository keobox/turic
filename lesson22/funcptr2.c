#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int compare_integers (const void *a, const void *b) {
    const int *ap = (int*) a;
    const int *bp = (int*) b;
    if (*ap > *bp) return 1;
    if (*ap < *bp) return -1;
    return 0;
}

int main (void) {
    int a[10];
    for (int j = 0; j < 10; j++) {
        /* Use a 0xF bit mask to limit the numbers value 0xF = b1111 */
        a[j] = rand() & 15;
    }
    a[2] = INT_MAX;
    a[5] = INT_MIN;
    for (int j = 0; j < 10; j++) {
        printf("%d ", a[j]);
    }
    qsort(a, 10, sizeof(int), compare_integers);
    printf("\n");
    for (int j = 0; j < 10; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
    return 0;
}
