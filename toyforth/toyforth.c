#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* ========================= Data Structures ======================== */

#define TF_OK 0
#define TF_ERR 1

#define TFOBJ_TYPE_INT 0
#define TFOBJ_TYPE_STR 1
#define TFOBJ_TYPE_BOOL 2
#define TFOBJ_TYPE_LIST 3
#define TFOBJ_TYPE_SYMBOL 4
#define TFOBJ_TYPE_ALL 255 /* used by listPopType() */

typedef struct tfobj {
    int refcount;
    int type; /* TFOBJ_TYPE_* */
    union {
        int i;
        struct {
            char *ptr;
            size_t len;
            // int quoted; // boolean
        } str;
        struct {
            struct tfobj **ele;
            size_t len;
        } list;
    };
} tfobj;

typedef struct tfparser {
    char *prg; /* The program to compile into a list */
    char *p;   /* The next token to parse */
} tfparser;

/* Function table entry: each of this entry represents a symbol
 * associated with a function implementation,
 */
struct tfctx;
typedef struct FunctionTableEntry {
    tfobj *name;
    int (*callback) (struct tfctx *ctx, char *name);
    /* user defined function */
    tfobj *user_func;
} tffuncentry;

struct FunctionTable {
    tffuncentry **func_table;
    size_t func_count;
};

/* Our execution context.
 */
typedef struct tfctx {
    tfobj *stack;
    struct FunctionTable functable;
} tfctx;



/* ====================== Object related functions ==================
 * The following functions allocate Toy Forth objects */

/* ====================== Function prototypes ======================== */

void retain(tfobj *o);
void release(tfobj *o);

/* ====================== Library prototypes ======================== */

int basicMathFunctions(tfctx *, char *);

/* ====================== Allocation Wrappers ======================= */

void *xmalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Out of memory allocating %zu bytes\n", size);
        exit(1);
    }
    return ptr;
}

void *xrealloc(void *oldptr, size_t size) {
    void *ptr = realloc(oldptr, size);
    if (ptr == NULL) {
        fprintf(stderr, "Out of memory allocating %zu bytes\n", size);
        exit(1);
    }
    return ptr;
}

/* Allocate and initialize a new Toy Forth object. */
tfobj *createObject(int type) {
    tfobj *o = (tfobj *)xmalloc(sizeof(tfobj));
    o->type = type;
    o->refcount = 1;
    return o;
}

tfobj *createIntObject(int i) {
    tfobj *o = createObject(TFOBJ_TYPE_INT);
    o->i = i;
    return o;
}

tfobj *createBoolObject(int i) {
    tfobj *o = createObject(TFOBJ_TYPE_BOOL);
    o->i = i;
    return o;
}

/* Forward declare to fix compilation error */
void release(tfobj *);

/* Free an object and all the other nested object */
void freeObject(tfobj *o) {
    assert(o->refcount == 0);

    switch (o->type) {
    case TFOBJ_TYPE_LIST:
        for (size_t j = 0; j < o->list.len; j++) {
            tfobj *ele = o->list.ele[j];
            release(ele); /* still recursive */
        }
        break;
    case TFOBJ_TYPE_SYMBOL:
    case TFOBJ_TYPE_STR:
        free(o->str.ptr);
        break;
    }
    free(o);
}

/* Free object and handle ref count
 */
void release(tfobj *o) {
    assert(o->refcount > 0);
    o->refcount--;
    if (o->refcount == 0)
        freeObject(o);
}

/* Increment ref count
 */
void retain(tfobj *o) { o->refcount++; }

/* ============================ String Object ======================== */

tfobj *createStringObject(char *s, size_t len) {
    tfobj *o = createObject(TFOBJ_TYPE_STR);
    o->str.ptr = xmalloc(len + 1);
    strncpy(o->str.ptr, s, len);
    o->str.ptr[len] = 0;
    o->str.len = len;
    return o;
}

tfobj *createSymbolObject(char *s, size_t len) {
    tfobj *o = createStringObject(s, len);
    o->type = TFOBJ_TYPE_SYMBOL;
    return o;
}

/* Compare two string objects 'a' and 'b', returns 0 if the are
 * the same, 1 if a>b, -1 if a<b the comparison is performed using
 * memcmp().
 */
int compareStringObject(tfobj *a, tfobj *b) {
    size_t minlen = a->str.len < b->str.len ? a->str.len : b->str.len;
    int cmp = memcmp(a->str.ptr, b->str.ptr, minlen);
    if (cmp == 0) {
        if (a->str.len == b->str.len) return 0;
        else if (a->str.len > b->str.len) return 1;
        else return -1;
    } else {
        if (cmp < 0) {
            return -1;
        } else {
            return 1;
        }
    }
}

/* ============================= List Object ======================== */

tfobj *createListObject(void) {
    tfobj *o = createObject(TFOBJ_TYPE_LIST);
    o->list.ele = NULL;
    o->list.len = 0;
    return o;
}

/* Push the new element at the end of the list "l".
 * It is up to the caller incrementing the reference count of
 * the element added to the list, if needed
 * */
void listPush(tfobj *l, tfobj *ele) {
    l->list.ele = xrealloc(l->list.ele, sizeof(tfobj *) * (l->list.len + 1));
    l->list.ele[l->list.len] = ele;
    l->list.len++;
}

tfobj *listPopType(tfctx *ctx, int type) {
    tfobj *stack = ctx->stack;
    if (stack->list.len == 0) return NULL;
    tfobj *to_pop = stack->list.ele[stack->list.len-1];
    if (type != TFOBJ_TYPE_ALL && to_pop->type != type) return NULL;

    stack->list.len--;
    if (stack->list.len == 0) {
        free(stack->list.ele);
        stack->list.ele = NULL;
    } else {
        stack->list.ele = xrealloc(stack->list.ele,
                sizeof(tfobj *) * (stack->list.len));
    }
    return to_pop;
}

tfobj *listPop(tfctx *ctx) {
    return listPopType(ctx, TFOBJ_TYPE_ALL);
}

/* ================ Turn program into toy forth list ================ */

void parseSpaces(tfparser *parser) {
    while (isspace(parser->p[0]))
        parser->p++;
}

#define MAX_NUM_LEN 128

tfobj *parseNumber(tfparser *parser) {
    char buf[MAX_NUM_LEN];
    char *start = parser->p;
    char *end;
    if (parser->p[0] == '-')
        parser->p++;
    while (parser->p[0] && isdigit(parser->p[0])) {
        parser->p++;
    }
    end = parser->p;
    int numlen = end - start;
    if (numlen >= MAX_NUM_LEN)
        return NULL;
    memcpy(buf, start, numlen);
    buf[numlen] = 0;
    tfobj *o = createIntObject(atoi(buf));
    return o;
}

/*
 * Returns true if the character 'c' is one of the characters
 * accetable for our symbols.
 */
int is_symbol_char(char c) {
    char symchars[] = "+-*/%";
    return isalpha(c) || strchr(symchars, c) != NULL;
}

tfobj *parseSymbol(tfparser *parser) {
    char *start = parser->p;
    while (parser->p[0] && is_symbol_char(parser->p[0])) {
        parser->p++;
    }
    int len = parser->p - start;
    return createSymbolObject(start, len);
}

tfobj *compile(char *prg) {
    tfparser parser;
    parser.prg = prg;
    parser.p = prg;

    tfobj *parsed = createListObject();

    while (parser.p[0]) {
        tfobj *o;
        char *token_start = parser.p;

        parseSpaces(&parser);
        if (parser.p[0] == 0)
            break; /* End of program */
        if (isdigit(parser.p[0]) ||
            (parser.p[0] == '-' && isdigit(parser.p[1]))) {
            o = parseNumber(&parser);
        } else if (is_symbol_char(parser.p[0])) {
            o = parseSymbol(&parser);
        } else {
            o = NULL;
        }

        /* Check if the current token produced a compilation parsing error */
        if (o == NULL) {
            release(parsed);
            printf("Syntax error near: %32s ... \n", token_start);
            return NULL;
        } else {
            listPush(parsed, o);
        }
    }
    return parsed;
}

/* ==================== Execute the Program ========================= */

void printObject(tfobj *o) {
    switch (o->type) {
    case TFOBJ_TYPE_INT:
        printf("%d", o->i);
        break;
    case TFOBJ_TYPE_LIST:
        printf("[");
        for (size_t j = 0; j < o->list.len; j++) {
            tfobj *ele = o->list.ele[j];
            printObject(ele);
            if (j != o->list.len - 1)
                printf(" ");
        }
        printf("]");
        break;
    case TFOBJ_TYPE_STR:
        printf("\"%s\"", o->str.ptr);
        break;
    case TFOBJ_TYPE_SYMBOL:
        printf("%s", o->str.ptr);
        break;
    default:
        printf("?");
    }
}

/* =================== Execution and context ======================== */

int ctxCheckStackMinLen(tfctx * ctx, size_t min) {
    return (ctx->stack->list.len < min) ? TF_ERR : TF_OK;
}

/* Pops an object from the interpreter stack, if it matches 'type'.
 * Returns NULL idf the stack is empty.
 *
 * The reference counting of the popped object is not modified.
 * Is assumed that we just transfer the ownership of the stack to
 * the caller.
 */
tfobj *ctxStackPop(tfctx *ctx, int type) {
    return listPopType(ctx, type);
}

/* Pushes an object in the interpreter stack.
 */
void ctxStackPush(tfctx *ctx, tfobj *obj) {
    listPush(ctx->stack, obj);
}
/* Resolve the function scanning the function table looking for a
 * matching name. If a matching function is not found, NULL is returned,
 * otherwise the function returns the function entry object.
 *
 */
tffuncentry *getFunctionByName(tfctx *ctx, tfobj *name) {
    for (size_t j=0; j < ctx->functable.func_count; j++) {
        tffuncentry *fe = ctx->functable.func_table[j] ;
        if (compareStringObject(fe->name, name) == 0) {
            return fe;
        }
    }
    return NULL;
}

/* Push a new function entry in the context. It's up to the caller
 * to set either the C callback or the list representing the user
 * defined function.
 */
tffuncentry *registerFunction(tfctx *ctx, tfobj *name) {
    ctx->functable.func_table = xrealloc(ctx->functable.func_table,
            sizeof(tffuncentry*) * (ctx->functable.func_count+1));
    tffuncentry *fe = xmalloc(sizeof(tffuncentry));
    ctx->functable.func_table[ctx->functable.func_count] = fe;
    ctx->functable.func_count++;
    fe->name = name;
    fe->callback = NULL;
    fe->user_func = NULL;
    /* Next retain not present in github version */
    retain(name);
    return fe;
}

/* Register a new function with the given name in the function table
 * of the context. The function can't fail since a function with the
 * same name exists, is replaced by a new one.
 *
 */
void registerCFunction(tfctx *ctx, char *name,
        int (*callback)(tfctx *ctx, char *name)) {
    tffuncentry *fe;
    tfobj *oname = createStringObject(name, strlen(name));
    fe = getFunctionByName(ctx, oname);
    if (fe) {
        if (fe->user_func) {
            release(fe->user_func);
            fe->user_func = NULL;
        }
        fe->callback = callback;
    } else {
        fe = registerFunction(ctx, oname);
        fe->callback = callback;
    }
    release(oname);
}

/* Create program (execution) context
 */
tfctx *createContext(void) {
    tfctx *ctx = xmalloc(sizeof(*ctx));
    ctx->stack = createListObject();
    ctx->functable.func_table = NULL;
    ctx->functable.func_count = 0;
	/* call a function in C */
	registerCFunction(ctx, "+", basicMathFunctions);
    return ctx;
}

/* Tries to resolve and call the function associated with the symbol
 * name 'word'. Returns 0 id the symbol was actually bound to a
 * function and was executed, returns 1 otherwise.
 */
int callSymbol(tfctx *ctx, tfobj *word) {
    tffuncentry *fe = getFunctionByName(ctx, word);
    /* TODO set error in context */
    if (fe == NULL) return TF_ERR;
    if (fe->user_func) {
        /* TODO implement me, call 'exec' */
        printf("Not implemented yet\n");
        return TF_ERR;
    } else {
        /* Call back case, stack frame should be necessary here */
        return fe->callback(ctx, fe->name->str.ptr);
    }
    return TF_OK;
}

/* Execute the code compiled in the 'prg' list */
int exec(tfctx *ctx, tfobj *prg) {
    /* Check prg is actually a list obj */
    assert(prg->type == TFOBJ_TYPE_LIST);

    for (size_t j = 0; j < prg->list.len; j++) {
        tfobj *word = prg->list.ele[j];
        switch (word->type) {
        case TFOBJ_TYPE_SYMBOL:
            /* Execute a symbol */
            if (callSymbol(ctx, word) == TF_ERR) {
                printf("Run time error\n");
                return TF_ERR;
            }
            break;
        default:
            /* Add on stack the other cases */
            ctxStackPush(ctx, word);
            retain(word);
            break;
        }
    }
    return TF_OK;
}

/* =================== Basic Standard Library ======================= */

int basicMathFunctions(tfctx *ctx, char *name) {
    if (ctxCheckStackMinLen(ctx, 2)) return TF_ERR;

#if 0
    /* TODO */
    if (ctxCheckTypes(ctx, TFOBJ_TYPE_INT, TFOBJ_TYPE_INT, -1));
#endif

    tfobj *b = ctxStackPop(ctx, TFOBJ_TYPE_INT);
    if (b == NULL) return TF_ERR;
    tfobj *a = ctxStackPop(ctx, TFOBJ_TYPE_INT);
    if (a == NULL) {
        ctxStackPush(ctx, b);
        return TF_ERR;
    }

    int result;
    switch (name[0]) {
    case '+': result = a->i + b->i; break;
    case '-': result = a->i - b->i; break;
    case '*': result = a->i * b->i; break;
    }
    release(a);
    release(b);
    ctxStackPush(ctx, createIntObject(result));
    return TF_OK;
}

/* ============================ Main ================================ */

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Read program in memory for later parsing */
    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp) {
        perror("Opening the Toy Forth program");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    char *prgtext = xmalloc(file_size + 1);
    fseek(fp, 0, SEEK_SET);
    fread(prgtext, file_size, 1, fp);
    prgtext[file_size] = 0;
    fclose(fp);

    tfobj *prg = compile(prgtext);
    printObject(prg);
    printf("\n");

    tfctx *ctx = createContext();
    exec(ctx, prg);
    printf("Stack content at end: ");
    printObject(ctx->stack);
    printf("\n");

    return 0;
}
