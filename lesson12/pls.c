#include <stdio.h>
#include <stdlib.h>

/* pls.c Prefixed Length String */

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'.
 *
 * The created string has the following layout:
 * +-+-----------\\\
 * |L|My string here
 * +-+-----------\\\
 *
 * Where L is one unsigned byte stating the total length of the string.
 * Thus this string are binary safe: bytes of value 0 are permitted in
 * the middle of the string.
 *
 * Warning: this function does not check for buffer overflow.
 */

char *ps_create(char *init, int len) {
    char *s = malloc(1 + len);
    unsigned char *lenptr = (unsigned char *) s;
    // write the length in the first byte
    *lenptr = len;
    // write the rest
    for (int j = 0; j < len ; j++) {
        s[j+1] = init[j];
    }
    return s;
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
    char *mystr = ps_create("Hello World", 11);
    ps_print(mystr);
    ps_print(mystr);
    return 0;
}
