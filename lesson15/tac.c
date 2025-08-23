#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char buf[1024];
    struct line *head = NULL;
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        /* the malloc return value should be checked for NULL:
           memory error */
        struct line *l = malloc(sizeof(struct line));
        size_t linelen = strlen(buf);
        l->s = malloc(linelen + 1);
        /* the string copy can be done with memcpy */
        for(size_t j = 0; j <= linelen; j++) {
            l->s[j] = buf[j];
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
