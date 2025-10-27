#include <stdio.h>
#include <stdlib.h>

#define TFOBJ_TYPE_INT 0
#define TFOBJ_TYPE_STR 1
#define TFOBJ_TYPE_BOOL 2
#define TFOBJ_TYPE_LIST 3
#define TFOBJ_TYPE_SYMBOL 4

typedef struct tfobj {
	int refcount;
	int type; /* TFOBJ_TYPE_* */
	union {
		int i;
		struct {
			char *ptr;
			size_t len;
		} str;
		struct {
			struct tfobj **ele;
			size_t len;
		} list;
	};
} tfobj;

typedef struct tfparser {
	char *prg; /* The program to compile into a list */
	char *p; /* The next token to parse */
} tfparser;

int main(int argc, char **argv) {
	return 0;
}
