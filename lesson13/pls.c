#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* pls.c Prefixed Length String */

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'.
 *
 * The created string has the following layout:
 * +-+---------------\\\
 * |LLLL|My string here
 * +-+---------------\\\
 *
 * Where LLLL are four unsigned bytes containing the total length of the string.
 * Thus these strings are binary safe: bytes of value 0 are permitted in
 * the middle of the string.
 *
 * Warning: this function does not check for buffer overflow.
 */

char *ps_create(char *init, uint32_t len) {
    char *s = malloc(4 + len + 1);
    uint32_t *lenptr = (uint32_t *) s;
    // write the length in the first 4 bytes
    *lenptr = len;
    s += 4;
    // write the rest
    for (uint32_t j = 0; j < len ; j++) {
        s[j] = init[j]; // FIXME use memcopy
    }
    s[len] = 0;
    return s;
}

/* Display the string s on the screen.
 */
void ps_print(char *s) {
    uint32_t *lenptr = (uint32_t *) (s-4);
    for (uint32_t j = 0; j < *lenptr; j++) {
        putchar(s[j]);
    }
    printf("\n");
}

/* Dealloc a prefixed length string */
void ps_free(char *s) {
    free(s-4);
}

int main(void) {
    char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
    ps_print(mystr);
    ps_print(mystr);
    printf("%s\n", mystr);
    ps_free(mystr);
    return 0;
}
