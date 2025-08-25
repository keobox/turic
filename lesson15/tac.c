#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 1024

struct line {
    char *s;
    struct line *next;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Missing file name\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File does not exists\n");
        return 1;
    }

    char buf[BUF_LEN];
    struct line *head = NULL;
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        /* the malloc return value should be checked for NULL:
           memory error */
        struct line *l = malloc(sizeof(struct line));
        size_t linelen = strnlen(buf, BUF_LEN);
        l->s = malloc(linelen);
        /* the string copy can be done with memcpy */
        for (size_t j = 0; j < linelen; j++) {
            l->s[j] = buf[j];
        }
        if (linelen == BUF_LEN) {
          /* since buffers are not zerod with memset */
          l->s[BUF_LEN] = '\0';
        }
        l->next = head;
        head = l;
    }

    while(head != NULL) {
        printf("%s", head->s);
        head = head->next;
    }

    fclose(fp);
    return 0;
}
