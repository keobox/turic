#include <stdio.h>
#include <ctype.h>

#define HEXDUMP_CHARS_PER_LINE 16
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
    /* FILE is a typedef of a struct */
    FILE *fp = fopen("stdio1.c", "r");
    if (fp == NULL) {
        printf("Unable to open the file\n");
        return 1;
    }
    char buf[32];
    size_t nread = fread(buf, 1, sizeof(buf), fp);
    hexdump(buf, nread);
    printf("%zd\n", nread);
    fclose(fp);
    return 0;
}
