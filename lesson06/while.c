#include <stdio.h>

int main(void) {
    int i = 0;

    loop:
    if (i < 10) goto enter_loop; // {
        goto next;
        enter_loop:
        printf("%d\n", i);
        i++;
        goto loop;               // }
    next:

    return 0;
}
