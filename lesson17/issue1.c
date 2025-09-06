#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pls {
    long len;
    char str[20];
};

#define HEXDUMP_CHARS_PER_LINE 8
void hexdump(void *p, size_t len) {
   unsigned char *byte = p;
   size_t po = 0;
   for (size_t j = 0; j < len; j++) {
       printf("%02X ", byte[j]);
       if ((j+1) % HEXDUMP_CHARS_PER_LINE == 0 || j == len-1) {
           if (j == len-1) {
               int pad = HEXDUMP_CHARS_PER_LINE -
                   (len % HEXDUMP_CHARS_PER_LINE);
               pad %= HEXDUMP_CHARS_PER_LINE;
               for (int i = 0; i < pad; i++) printf("~~ ");
           }
           printf("\t");
           for (size_t i = po; i <= j ; i++) {
               /* isprint = is_printable */
               char c = isprint((char)byte[i]) ? byte[i] : '.';
               printf("%c", c);
           }
           printf("\n");
           po = j+1;
       }
   }
}

int main(void) {
    struct pls s;

    /* memset(&s, 0xFF, sizeof(s)); */
    s.len = 10;
    memcpy(s.str, "1234567890", 11);
    printf("%p\n", &s);
    printf("%p\n", s.str);
    hexdump(&s, sizeof(s));
    return 0;
}
