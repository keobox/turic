#include <stdio.h>

void hello(void) {
    printf("hello!\n");
}

void baubau(void) {
    printf("baubau!\n");
}

void call_n_times(int n, void(*x)(void)) {
    while (n--) {
        x();
    }

}
int main (void) {

    call_n_times(10, hello);
    call_n_times(10, baubau);

    return 0;
}
