#include <stdio.h>

void count(int start, int end) {
    if (start > end) return;
    printf("%d %p\n", start, &start);
    count(start+1, end);
}

void count_tail_call_optimized(int start, int end) {
iterate:
    if (start > end) return;
    printf("%d %p\n", start, &start);
    start = start + 1;
    goto iterate;
}


int main(void) {
    count(0, 9);
    printf("\n");
    count_tail_call_optimized(0,9);
    return 0;
}
