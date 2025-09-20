#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


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
    /* Use the standard posix function to open a file,
       it returns the file descriptor as integer or -1 */
    int fd = open("stdio3.c", O_RDONLY);
    if (fd == -1) {
        perror("Unable to open the file");
        return 1;
    }
    close(fd);

#if 0
    char buf[32];
    size_t nread;
    while (1) {
        nread = fread(buf, 1, sizeof(buf), fp);
        if (nread == 0)
            break;
        hexdump(buf, nread);
    }
    printf("%zd\n", nread);
    fclose(fp);
#endif
    return 0;
}
