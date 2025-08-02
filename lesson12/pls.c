#include <stdio.h>

/* pls.c Prefixed Length String */

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'.
 *
 * Warning: this function does not check for buffer overflow.
 */

void ps_init(char *s, char *init, int len) {
    unsigned char *lenptr = (unsigned char *) s;
    // write the length in the first byte
    *lenptr = len;
    // write the rest
    for (int j = 0; j < len ; j++) {
        s[j+1] = init[j];
    }
}

/* Display the string s on the screen.
 */
void ps_print(char *s) {
    unsigned char *lenptr = (unsigned char *) s;
    for (int j = 0; j < *lenptr; j++) {
        putchar(s[j+1]);
    }
    printf("\n");
}

int main(void) {
    char buf[256];
    ps_init(buf, "Hell\000 World", 11);
    ps_print(buf);
    ps_print(buf);
    return 0;
}
