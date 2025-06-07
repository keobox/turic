#include <stdio.h>
#include <limits.h>

int main(void) {
    char c = 1; // 8 bit, 1 byte
    short s = 2000; // 16 bit, 2 bytes
    int x = 5; // 4 bytes, 32 bits
    long l = 10; // it's the word of the HW: i.e 8 bytes, 64 bits in case of HW 64 bit
    printf("Hello World: long size %lu\n", sizeof(l));
    return 0;
}
