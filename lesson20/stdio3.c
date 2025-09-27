#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(void) {
    int fd = open("stdio3.c", O_RDONLY);
    printf("Open file descriptor: %d\n", fd);
    void *mem = mmap(NULL, 100, PROT_READ, MAP_FILE|MAP_SHARED, fd, 0);
    printf("File mapped at %p\n", mem);
    printf("%c", ((char*)mem)[0]);
    return 0;
}
