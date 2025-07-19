#include <stdio.h>

int main(void) {
    char mystr[] = "AABBCCDDEEFF";
    short *p = (short*) mystr;
    /* Since asc of 'A' is 65 this will print
       65 + 65 * 256 the decimal value of the
       first 2 bytes "AA" */
    printf("%d\n", *p);

    p++;
    /* The pointer increment above will
    increment the address by sizeof(short), the
    type of the pointer, so p in now pointing to BB
    and since asc 'B' is 66, the printf will print
    66 + 66 * 256 */
    printf("%d\n", *p);

    p = (short*) mystr;
    /* Will print "EE" in decimal = 17733 */
    printf("%d\n", p[4]);
    return 0;
}
