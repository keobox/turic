#include <stdio.h>

/* errorcode is an int alias */
typedef int errorcode;

errorcode foo(void) {
    return -20;
}
int main(void) {
    errorcode a = foo();
    printf("%d\n", a);
    return 0;
}
