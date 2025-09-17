#include <stdio.h>

int main(void) {
    /* FILE is a typedef of a struct */
    FILE *fp = fopen("stdio1.c", "r");
    if (fp == NULL) {
        printf("Unable to open the file\n");
        return 1;
    }
    char buf[32];
    size_t nread = fread(buf, 1, sizeof(buf), fp);
    printf("%zd\n", nread);
    fclose(fp);
    return 0;
}
