#include <stdio.h>

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

    fclose(fp);
    return 0;
}
