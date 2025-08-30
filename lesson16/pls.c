#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct pls {
    uint32_t len;
    uint32_t refcount;
    uint32_t magic;
    char str[];
};

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
 * CCCC is the space for reference counting.
 *
 * Warning: this function does not check for buffer overflow.
 */

char *ps_create(char *init, uint32_t len) {
    struct pls *p = malloc(sizeof(struct pls)+ len + 1);
    p->len = len;
    p->refcount = 1;
    p->magic = 0xDEADBEEF;

    // write the rest
    for (uint32_t j = 0; j < len ; j++) {
        p->str[j] = init[j]; // FIXME use memcopy
    }
    p->str[len] = 0;
    return p->str;
}

/* Display the string s on the screen.
 */
void ps_print(char *s) {
    /* For backward compatibility with C standard strings
       pls.str is returned by ps_create but we know that
       struct pls is the "header" of a prefixed length string
       so to obtain the pointer to the original malloc in
       ps_create we have to substract the size of the
       pls struct from the regular string 's' is pointing to.
    */
    struct pls *p = (struct pls *) (s - sizeof(*p));
    for (uint32_t j = 0; j < p->len; j++) {
        putchar(p->str[j]);
    }
    printf("\n");
}

/* Dealloc a prefixed length string */
void ps_free(char *s) {
    free(s - sizeof(struct pls));
}

/* Checks the magic field */
void ps_validate(struct pls *p) {
    if (p->magic != 0xDEADBEEF) {
        printf("INVALID STRING: Aborting\n");
        exit(1);
    }
}

/* Dealloc the string in case there are no more references to it.
*/
void ps_release(char *s) {
    struct pls *p = (struct pls *) (s - sizeof(*p));
    ps_validate(p);

    p->refcount--;
    if (p->refcount == 0) {
        p->magic = 0;
        ps_free(s);
    }
}

/* Increments the counter
*/
void ps_retain(char *s) {
    struct pls *p = (struct pls *) (s - sizeof(*p));
    if (p->refcount == 0) {
        printf("ABORTED ON RETAIN OF ILLEGAL STRING.\n");
        exit(1);
    }
    p->refcount++;
}

/* Returns the string's length in O(1) */
uint32_t ps_len(char *s) {
    struct pls *p = (struct pls *) (s - sizeof(*p));
    return p->len;
}

char *global_string;

int main(void) {
    char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
    global_string = mystr;
    ps_retain(global_string);
    ps_print(mystr);
    ps_print(mystr);
    printf("%s %d\n", mystr, (int)ps_len(mystr));
    ps_release(mystr);
    printf("%s\n", global_string);
    ps_release(global_string);
    /* simulate free error */
    // ps_release(mystr);
    return 0;
}
