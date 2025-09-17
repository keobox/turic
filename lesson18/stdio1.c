#include <stdio.h>

int main(void) {
    /* FILE is a typedef of a struct */
    FILE *fp = fopen("stdio1.c", "r");
    if (fp == NULL) {
        printf("Unable to open the file\n");
        return 1;
    }

    fclose(fp);
    return 0;
}
