#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* pls.c Prefixed Length String */

/* Initialize a prefixed length string with the specified
 * string in 'init' of length 'len'.
 *
 * The created string has the following layout:
 * +-+-------------------\\\
 * |LLLL|CCCC|My string here
 * +-+-------------------\\\
 *
 * Where LLLL are four unsigned bytes containing the total length of the string.
 * Thus these strings are binary safe: bytes of value 0 are permitted in
 * the middle of the string.
 *
 * Warning: this function does not check for buffer overflow.
 */

char *ps_create(char *init, uint32_t len) {
    char *s = malloc(8 + len + 1);
    uint32_t *lenptr = (uint32_t *) s;
    uint32_t *count = (uint32_t *)(s + 4);
    *lenptr = len;

    s += 8;
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

/* Returns the string's length in O(1) */
uint32_t ps_len(char *s) {
    uint32_t *lenptr = (uint32_t *) (s-4);
    return *lenptr;
}

char *global_string;

int main(void) {
    char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
    global_string = mystr;
    ps_print(mystr);
    ps_print(mystr);
    printf("%s %d\n", mystr, (int)ps_len(mystr));
    ps_free(mystr);
    // printf("%s\n", global_string);
    return 0;
}
