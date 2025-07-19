#include <stdio.h>

int main(void) {
    char mystr[] = "Hello World";
    char *p = mystr;
    printf("At %p I can see: %s\n", mystr, mystr);
    printf("At %p I can see: %s\n", p, mystr);
    return 0;
}
