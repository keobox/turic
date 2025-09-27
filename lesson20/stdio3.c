#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char *mystr = "Hello World";
    size_t len = strlen(mystr);
    for (size_t j=0; j < len; j++)
        putchar(mystr[j]);
    fflush(stdout);
    sleep(5);
    return 0;
}
