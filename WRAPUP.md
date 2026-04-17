# Turic - Course Wrap-Up

A C programming course by **Salvatore Sanfilippo (Antirez)**, 31 lessons delivered as
live-coding YouTube sessions. The course starts from "Hello World" and builds up to a
Forth language interpreter and an evolutionary image processing tool, covering most of
the C language along the way.

---

## Lesson-by-Lesson Summary

### Lesson 01 - Introduction to C and Compilation

Video: https://youtu.be/HjXBXBgfKyk?si=xWaCOH-INehqLIAq

- `#include` directives and the C preprocessor
- Function prototypes: declaring `printf` manually without the header
- `#include "file.c"` to inline another source file
- Compilation to assembly, compiler optimization levels (`-O2`)
- Variadic function syntax (`...`), the `restrict` keyword

### Lesson 02 - Local Variables, Stack, and Function Calls

Videos:
- https://youtu.be/Z84vlG1RRtg?si=rk9wWnZupMpOyqGv
- https://www.youtube.com/watch?v=r6mU_IHXEps&t=14s

- GCC warning flags
- `printf` format strings and variadic argument promotion (short->int, float->double)
- `main(void)` as entry point, return value as Unix exit code
- Local variable initialization: declaration+init vs. separate assignment
- Function arguments as local copies (pass-by-value)
- Stack memory model, stack pointer, push/pop
- 6502 and x86 assembly to illustrate function call conventions
- Local variables stored in registers or spilled to stack

### Lesson 03 - Primitive Data Types and Type Conversions

Video: https://www.youtube.com/watch?v=mw4gUqsGPZw&t=7s

- Global variables vs. local variables
- `static` variables: file-scoped, visible only within a function
- Thread safety issues with global/static state
- Pass-by-value semantics and return values
- `float` type and floating-point representation quirks
- `char` type and character literals
- Signed overflow is **undefined behavior**; unsigned overflow wraps (guaranteed)
- Implicit type promotion in expressions and function calls
- Format string mismatches causing UB

### Lesson 04 - Integer Types, Sizes, and System Architecture

Video: https://www.youtube.com/watch?v=YNsXyasn4R4

- `sizeof` operator to inspect type sizes at compile time
- `<limits.h>` for platform-specific integer ranges
- C standard does not guarantee type sizes
- `long` as the hardware word size
- `<stdint.h>` fixed-width types: `uint64_t`, `int64_t`, `size_t`, `intptr_t`
- Buffer flushing with `fflush()`, automatic flush on `\n`
- Strings as sequences of `char`
- VT100 escape sequences (`\x1b[H`) for terminal control

### Lesson 05 - Arrays and Strings

Video: https://www.youtube.com/watch?v=SWWHqgSwQFw

- Array declaration and initialization: `int a[5] = {10, 5, 50, 100, 7};`
- Single quotes for `char` literals (ASCII values)
- String literals as null-terminated `char` arrays
- The NUL terminator (`\0`, value 0)
- `char str[] = "hello"` is mutable (array, not pointer to literal)
- `sizeof` on arrays gives compile-time size

### Lesson 06 - Control Flow: Conditionals, Loops, and Recursion

Video: https://www.youtube.com/watch?v=lc7aYXNl1T8&list=WL&index=81

- Curly braces define code blocks; block scope for variables
- Variable shadowing in nested blocks
- Printing pointer values with `%p`, address-of operator `&`
- Stack layout: observing 4-byte alignment gaps between `int` variables
- `if` and `goto` as the primitive control flow
- `while` loop as an abstraction over `if`/`goto`
- Recursion as an alternative to loops
- Stack memory cost of deep recursion

### Lesson 07 - Advanced Control Flow: For Loops, TCO, and Switch

Video: https://www.youtube.com/watch?v=HCRthhjbfAg

- **Tail Call Optimization (TCO)**: converting recursion into `goto`-based iteration
- `for` loops as syntactic sugar over `while`
- Variations: omitting init, condition, or increment in `for`
- Scoped variables in `for` loop headers (C99)
- Using array sentinel values in loop conditions
- `switch` and fall-through behavior
- `case` labels are essentially `goto` targets
- Block scope needed for local variables inside `case`
- Recursive file-globbing pattern matching with `switch`

### Lesson 08 - Abstractions and Conway's Game of Life

Video: https://www.youtube.com/watch?v=c5atNuYdKK8

- `#define` for compile-time constants
- Designing layered abstractions: low-level primitives -> higher-level operations
- **2D-to-1D array mapping**: `index = y * COLS + x`
- Wrapping / toroidal boundary conditions with modulo arithmetic
- Nested loops for 2D grid iteration
- `continue` statement
- VT100 escape sequences for screen clearing
- **Double buffering** pattern (old_grid / new_grid)
- `usleep()` from `<unistd.h>` for animation timing
- Complete Game of Life implementation (~110 lines)

### Lesson 09 - Pointer Basics and Pass-by-Reference

Video: https://www.youtube.com/watch?v=BBgZs-jd_QY&list=WL&index=75

- Pointer declaration style: `int *p` (star near the variable)
- Setting a pointer to a stack variable's address
- Dereferencing to read and write through a pointer
- Pointer type determines how many bytes are read/written
- Simulating pass-by-reference with pointers: `void incr(int *x)`

### Lesson 10 - Pointer Arithmetic and Array Equivalence

Video: https://www.youtube.com/watch?v=lc7hL9Wt-ho

- `*p` is equivalent to `p[0]`
- All pointers are just numbers (address-bus width)
- Pointer-to-pointer
- Casting pointers to `int`
- Array variables decay to pointers (no `&` needed)
- **Pointer arithmetic is type-aware**: `*(p+1)` advances by `sizeof(*p)` bytes
- Demo: navigating a string with `char *` vs. `short *`
- Building a custom `printstr()` that walks a `char *`

### Lesson 11 - Prefix-Length Strings and Pointer Applications

Video: https://www.youtube.com/watch?v=msGzuneFpDU

- **Pascal-style prefix-length strings**: first byte stores length
- Binary representation, bit shifting, why 256 = 2^8
- Distinguishing character `'0'` from numeric `0`
- Octal notation (`\017`) to embed length bytes
- Refactoring Game of Life with pointer swapping to remove code duplication
- VT100 escape sequences revisited

### Lesson 12 - Dynamic Memory and Binary Search Trees

Videos:
- https://www.youtube.com/watch?v=ZkaKwWXJXs8
- https://www.youtube.com/watch?v=soiBgJjAmP8&t=71s

- `malloc()` and `free()` for dynamic memory
- Casting pointers for type manipulation
- Defensive programming: checking `malloc` return for `NULL`
- Prefix-length string with `malloc`: `[len_byte][data...]`
- **Binary Search Tree** from scratch:
  - `struct node` with `int value`, `left`, `right` pointers
  - Iterative insertion maintaining BST property
  - **Inorder traversal** (recursive) for sorted output
  - **Postorder traversal** (recursive) for tree deletion (children before parent)
- `sizeof(*ptr)` pattern for allocation

### Lesson 13 - Flexible String Headers and O(1) Length

Video: https://www.youtube.com/watch?v=9AhaOdEBmPc

- Expanding the length field from 1 byte to 4 bytes (`uint32_t`)
- `#include <stdint.h>` for fixed-width integer types
- **Hidden metadata header behind a pointer**: caller sees the string, header is at a negative offset
- `ps_len()` in O(1) by reading the header
- `ps_free()` subtracts header size to find the original `malloc` address
- Pointer arithmetic for managing hidden metadata

### Lesson 14 - Structs and Data Aggregation

Video: https://www.youtube.com/watch?v=p4IMHau2lq8

- `struct` for grouping related data
- Fraction type: creation, printing, simplification (finding GCD)
- **Memory alignment and padding**: struct size rounded to multiple of largest field
- Dot notation `.` for struct values, arrow notation `->` for struct pointers
- Returning structs by value (implicit copy)
- Preview: using a struct for the prefix-length string header

### Lesson 15 - File I/O and Linked Lists

Video: https://www.youtube.com/watch?v=aTT2W5NACEY

- `argc` and `argv` for command-line arguments
- `FILE *`, `fopen()`, `fgets()`, `fclose()`
- **Linked list**: `struct line` with string pointer and `next` pointer
- Implementing `tac` (reverse `cat`): read lines into a linked list, print in reverse
- `strnlen()` for safe length calculation
- Defensive programming: NULL checks on `fopen` and `malloc`
- O(N) time and space complexity analysis

### Lesson 16 - Reference Counting with Flexible Array Members

Video: https://www.youtube.com/watch?v=VPs_QtlLNcs

- **Flexible Array Member (FAM)** - C99: `char str[]` as last struct member
- FAM takes zero bytes in `sizeof`; actual size determined at `malloc` time
- Memory layout: `[len][refcount][magic][str...]`
- Magic field (`0xDEADBEEF`) for corruption detection
- **Reference counting**: `ps_retain()` increments, `ps_release()` decrements and frees at zero
- `#ifdef` for conditional compilation (removing magic field in production)
- Pointer offset calculations: `s - sizeof(struct pls)` to reach the header

### Lesson 17 - Struct Layout, Hexdump, and Flexible Arrays (continued)

Video: https://www.youtube.com/watch?v=grkIJjw6o18

- `char *str` (pointer) vs. `char str[]` (FAM, inline data) in structs
- Ternary operator `?:`
- **Hexdump function**: displays memory in hex + ASCII columns
- `isprint()` from `<ctype.h>` for printable character detection
- `memcpy()` for copying data into inline arrays
- Reference count overflow safeguard (treat as "internalized" string)

### Lesson 18 - Typedef and Opaque Types

Video: https://www.youtube.com/watch?v=3w73xjUSUEU&t=10s

- `typedef` for type aliases: `typedef struct { int n; int d; } fract;`
- `typedef` of a pointer: `typedef fract *fractptr;`
- **Opaque types**: exposing only a handle without revealing internals
- Real-world example: `FILE *` from `fopen()` - the user never sees the struct
- Introduction to `fread()` for block-based file reading

### Lesson 19 - System Calls vs. Libc Wrappers

Video: https://www.youtube.com/watch?v=QWLJ7CBAu_I

- POSIX `open()` with flags (`O_RDONLY`) vs. Libc `fopen()`
- **Flags as bitmasks**
- `errno` - thread-local error variable
- `perror()` for human-readable error messages
- Kernel space vs. user space memory protection
- `read()` returns `ssize_t` (signed) to signal errors with `-1`
- `write()` system call for output
- `read()` may return fewer bytes than requested (important for sockets)
- Headers: `<fcntl.h>`, `<errno.h>`, `<unistd.h>`

### Lesson 20 - I/O Buffering and Memory Mapping with mmap()

Video: https://www.youtube.com/watch?v=yKavhObop5I

- Why Libc buffers I/O: reducing system call overhead
- `printf` before `sleep` may appear out of order (buffering)
- `fflush()` to force flush; `\n` triggers auto-flush
- Portability: ANSI C Libc vs. OS-specific system calls
- **`mmap()`**: maps file content directly into process memory
- `mmap()` flags: `PROT_READ`, `MAP_FILE|MAP_SHARED`
- Mapped file accessed as a plain `char *` array
- Performance comparison: system calls (unbuffered) < Libc (buffered) < mmap (fastest for bulk)

### Lesson 21 - Unions and Bitfields

Video: https://www.youtube.com/watch?v=TM4jgODgdFY

- **`union`**: overlapping memory, only one field active at a time
- Demonstrating little-endian vs. big-endian byte order
- Real-world union example from Redis: `exprtoken` DSL
- **Bitfields**: `unsigned int field:4;` packs multiple fields into fewer bytes
- Bitfield overflow: unsigned wraps silently, signed is UB
- Applications: network packet headers, file format headers, memory optimization
- Real-world bitfields: Linux `struct iphdr`, Redis `redisObject`
- `assert()` for size verification

### Lesson 22 - Function Pointers and Callbacks

Video: https://www.youtube.com/watch?v=OIseV5lcx8w

- Functions live at memory addresses, just like data
- **Function pointer syntax**: `void (*fp)(void)`
- Passing function pointers as arguments: higher-order programming in C
- **`qsort()` from `<stdlib.h>`**: generic sorting via comparison callback
- Comparison function: `int cmp(const void *a, const void *b)`
- Casting `const void *` to specific pointer types
- `rand()` and bitmask tricks (`rand() & 15`)
- Integer overflow pitfalls in comparison functions
- Foreshadowing: function pointers in structs = objects

### Lesson 23 - Toy Forth Interpreter, Part 1

Video: https://www.youtube.com/watch?v=vYODKK8TQGE

- Building a **Forth interpreter** (stack-based / concatenative language)
- Forth basics: `5 5 +` -> `10`, `5 dup +` -> `10`
- **Tagged union (discriminated union)** for a polymorphic object type:
  - `tfobj` struct with `refcount`, `type` tag, and union of int/string/list
  - Object types: INT, STR, BOOL, LIST, SYMBOL
- `xmalloc()` wrapper: abort on OOM instead of propagating NULL
- **Factory functions**: `createIntObject()`, `createStringObject()`, etc.
- Interpreter context struct `tfctx` holding the stack
- Parser state struct `tfparser` (program pointer + current position)
- Reference to Joy (concatenative language)

### Lesson 24 - Toy Forth Interpreter, Part 2

Video: https://www.youtube.com/watch?v=-QxrmHo-V7Y

- Why **dynamic arrays beat linked lists**: cache locality, O(1) access, amortized O(1) append
- Over-allocation strategy with `realloc()`
- File size measurement: `fseek()` + `ftell()`
- **Tokenizer / lexer implementation**:
  - `parseSpaces()`: skip whitespace
  - `parseNumber()`: parse integers (including negative)
  - Main loop: classify and dispatch to parsers
- `isspace()`, `isdigit()` from `<ctype.h>`, `atoi()` for string-to-int
- `compile()` function: source text -> list of token objects
- `exec()` stub: walk the token list
- `memcpy()` for extracting parsed substrings

### Lesson 25 - Toy Forth Interpreter, Part 3

Video: https://www.youtube.com/watch?v=-1ZhCgaIPOk

- `parseSymbol()` function for tokenizing identifiers
- `is_symbol_char()`: alphanumeric plus `-*/%`
- **Recursive `print_object()`** with `switch` on type tag
- Nested list printing via recursion
- Bug fix: preventing `-` from being consumed as a symbol during number parsing
- Preparation for the `exec()` execution engine

### Lesson 26 - Toy Forth Interpreter, Part 4

Video: https://www.youtube.com/watch?v=oMj3N6jYIUU

- **Reference counting in action**: `retain()`, `release()`, `freeObject()`
- `freeObject()` recursively frees nested list elements
- `assert()` to verify refcount invariants
- `xrealloc()` wrapper for safe reallocation
- **Execution context** (`tfctx`): stack + function table
- Symbol quoting for literal symbol pushing
- `FunctionTableEntry` struct: name + C callback pointer + user-defined Forth code pointer
- Dual-mode function system: native C functions alongside user-defined Forth words

### Lesson 27 - Toy Forth Interpreter, Part 5

Video: https://www.youtube.com/watch?v=C4AHEK3fSjg

- **Binary-safe string comparison** with `memcmp()` (handles embedded NULs, unlike `strcmp()`)
- Proper length-aware comparison: compare up to min length, then compare lengths
- **Function table management**:
  - `getFunctionByName()`: linear scan lookup
  - `registerFunction()`: dynamic table expansion
  - `registerCFunction()`: binds a C callback, handles replacement of existing entries
- Memory management of registered function names (retain/release)

### Lesson 28 - Variadic Functions

Video: https://www.youtube.com/watch?v=cvWbCx0lLjs

- `<stdarg.h>` macros: `va_start`, `va_arg`, `va_copy`, `va_end`
- Ellipsis syntax `...` in function signatures
- **`vsnprintf()` and the v-series functions**: accept `va_list` instead of `...`
- Type safety trade-off: variadic functions lose compile-time checking
- Real-world examples from Antirez's projects:
  - `botlib` (Telegram bots)
  - `json_wrap.c` (cJSON wrapper)
  - `sqlite_wrap.c` (SQLite wrapper)
  - `stonky` (financial bot)
- Variadic functions as a tool for building higher-level API wrappers

### Lesson 29 - Toy Forth: First Execution

Video: https://www.youtube.com/watch?v=nHzlRqPnlrE

- First successful execution of Toy Forth programs
- Moving toyforth.c to its own directory
- **Makefile conventions**: first target is `all`
- Code review process (submitted to Claude for bug detection)
- Runtime error handling improvements
- Testing with deliberately malformed programs (negative test cases)

### Lesson 30 - ZXfy: ZX Spectrum Image Evolution

Video: https://www.youtube.com/watch?v=D1U3uCe-kok&t=5s

- Real-world C application: converting PNG to **ZX Spectrum** format
- ZX Spectrum hardware: 256x192 pixels, 8x8 color attribute blocks, 3-bit ink/paper colors
- **Evolutionary / genetic algorithm** for image optimization
- **Simulated annealing**: temperature-based acceptance to escape local minima
- **Curriculum learning**: progressive refinement (B&W first, then color)
- External library integration: SDL for display, libpng for I/O
- `computeDiff()`: RGB distance metric (Euclidean in 3D color space)
- `mutate()`: random mutations on pixel/attribute data
- `zx2rgb()`: ZX Spectrum ULA color conversion
- Bit manipulation for hardware-constrained color formats
- Source: https://github.com/antirez/zxfy

### Lesson 31 - ZXfy: Profiling and Optimization

Videos:
- https://www.youtube.com/watch?v=fZmdsh0gQig
- https://www.youtube.com/watch?v=xaEr-XSlWfo

- **Profiling** with macOS `sample` tool: found `computeDiff()` at 94.2% CPU
- Optimization: work on 8x8 blocks instead of full image
- Block-aligned optimization creates JPEG-like artifacts (local minima)
- Solution: unaligned 8x8 blocks to break attribute-block boundaries
- `computeBlockDiff()` and `mutateBlock()` for localized operations
- Command-line argument parsing: `--no-sdl`, `--zoom`
- Loss monitoring and convergence detection
- Color bonus to prevent color drift (dischromia)
- Saturation boost and brightness-only mode

---

## C Language Features Covered

### Preprocessor

| Feature | Lesson |
|---------|--------|
| `#include` (system and local) | 01 |
| `#define` constants | 08 |
| `#ifdef` / conditional compilation | 16 |

### Types and Data Representation

| Feature | Lesson |
|---------|--------|
| Primitive types: `char`, `short`, `int`, `long`, `float` | 03, 04 |
| `unsigned` vs. signed, overflow behavior | 03 |
| `sizeof` operator | 04, 05 |
| `<limits.h>` constants | 04 |
| `<stdint.h>` fixed-width types (`uint32_t`, `size_t`, etc.) | 04, 13 |
| Arrays and array initialization | 05 |
| Strings as null-terminated `char` arrays | 05 |
| `struct` definition, layout, alignment, padding | 14 |
| `union` (overlapping memory, type punning) | 21 |
| Bitfields (`unsigned int field:N`) | 21 |
| `typedef` and opaque types | 18 |
| Flexible Array Members (C99) | 16, 17 |
| Tagged unions / discriminated unions | 23 |
| `enum`-style constants via `#define` | 23 |

### Pointers and Memory

| Feature | Lesson |
|---------|--------|
| Address-of (`&`) and dereference (`*`) | 06, 09 |
| Pointer arithmetic (type-aware) | 10 |
| Array-pointer equivalence (`*p == p[0]`) | 10 |
| Pointer-to-pointer | 10 |
| Pass-by-reference via pointers | 09 |
| `malloc()`, `free()` | 12 |
| `realloc()` for dynamic arrays | 24, 26 |
| `xmalloc()` / `xrealloc()` wrappers (abort on OOM) | 23, 26 |
| Hidden metadata headers behind pointers | 13 |
| Reference counting (retain/release) | 16, 26 |
| `memcpy()`, `memcmp()` | 17, 24, 27 |
| `mmap()` for memory-mapped files | 20 |

### Control Flow

| Feature | Lesson |
|---------|--------|
| `if` / `else` | 06 |
| `goto` and labels | 06 |
| `while`, `do-while` | 06 |
| `for` loop (and variations) | 07 |
| `break`, `continue` | 07, 08 |
| `switch` / `case` (fall-through, scoped blocks) | 07 |
| Recursion | 06 |
| Tail call optimization via `goto` | 07 |
| Ternary operator `?:` | 17 |

### Functions

| Feature | Lesson |
|---------|--------|
| Function prototypes and definitions | 01 |
| Pass-by-value semantics | 03 |
| Returning structs by value | 14 |
| **Function pointers** and callbacks | 22 |
| `qsort()` with comparison function | 22 |
| **Variadic functions** (`...`, `va_list`, `va_start`, `va_arg`, `va_end`) | 28 |
| `vsnprintf()` and v-series functions | 28 |

### Standard Library (`libc`)

| Function / Header | Purpose | Lesson |
|-------------------|---------|--------|
| `printf`, `fprintf`, `sprintf` | Formatted output | 01+ |
| `fflush()` | Force buffer flush | 04, 20 |
| `fopen`, `fgets`, `fread`, `fclose` | Buffered file I/O | 15, 18 |
| `fseek`, `ftell` | File positioning / size | 24 |
| `strlen`, `strnlen` | String length | 15 |
| `strcmp`, `memcmp` | String/memory comparison | 27 |
| `atoi` | String to integer | 24 |
| `isprint`, `isspace`, `isdigit` | Character classification (`<ctype.h>`) | 17, 24 |
| `assert()` | Runtime invariant checks (`<assert.h>`) | 21, 26 |
| `rand()` | Random number generation | 22 |
| `usleep()` | Microsecond delay (`<unistd.h>`) | 08 |
| `perror()` | Print errno message | 19 |
| `qsort()` | Generic sorting | 22 |

### System Calls (POSIX)

| Call | Purpose | Lesson |
|------|---------|--------|
| `open()` / `close()` | Low-level file descriptors | 19 |
| `read()` / `write()` | Unbuffered I/O | 19 |
| `mmap()` | Memory-mapped files | 20 |
| `errno`, `ENOENT` | Error reporting | 19 |

---

## Data Structures Implemented

| Structure | Where | Lesson |
|-----------|-------|--------|
| 1D array as 2D grid (flattened) | Game of Life | 08, 11 |
| Prefix-length string (Pascal-style) | pls.c | 11, 12, 13, 16 |
| Binary Search Tree | bst.c | 12 |
| Singly linked list | tac.c | 15 |
| Reference-counted object with FAM | pls.c | 16, 17 |
| Tagged union (polymorphic object) | toyforth.c | 23 |
| Dynamic array / vector (over-allocated) | toyforth.c | 24 |
| Function table (linear scan) | toyforth.c | 26, 27 |
| Stack (via dynamic array) | toyforth.c | 26 |

---

## Programming Techniques Showcased

| Technique | Context | Lesson |
|-----------|---------|--------|
| Layered abstraction design | Game of Life helper functions | 08 |
| Double buffering | Game of Life old/new grids | 08, 11 |
| Pointer swapping to avoid copies | Game of Life grid swap | 11 |
| Hidden header behind a pointer | Prefix-length strings | 13 |
| Factory functions (constructors) | Object creation in toyforth | 23 |
| Opaque handle pattern | `typedef` + pointer | 18 |
| Callback-based generics | `qsort()` comparison function | 22 |
| Abort-on-error allocation | `xmalloc()` | 23 |
| Tokenizer / lexer | Forth parser (`compile()`) | 24, 25 |
| Stack-based virtual machine | Forth `exec()` | 26 |
| Recursive tree traversal | BST inorder/postorder | 12 |
| Recursive pretty-printing | `print_object()` for nested lists | 25 |
| Binary-safe string operations | `memcmp()` instead of `strcmp()` | 27 |
| API wrappers via variadic functions | Higher-level C library interfaces | 28 |
| Evolutionary algorithm | ZXfy image optimization | 30 |
| Simulated annealing | ZXfy temperature schedule | 30 |
| Profiling-driven optimization | `sample` tool, block-level computation | 31 |
| Curriculum learning | Progressive B&W -> color refinement | 30, 31 |

---

## Projects Built During the Course

### Conway's Game of Life (Lessons 08, 11)
Terminal-based Game of Life with toroidal grid wrapping, double buffering, and VT100
escape sequences for animation. Demonstrates building clean abstractions from low-level
array operations.

### `tac` - Reverse Cat (Lesson 15)
Reads a file into a linked list and prints lines in reverse order. Covers file I/O,
command-line arguments, and dynamic memory allocation.

### Prefix-Length Strings (Lessons 11-13, 16-17)
Evolved across multiple lessons from a 1-byte length prefix to a full struct with
`uint32_t` length, reference counting, magic validation field, and flexible array
member. A miniature version of Redis SDS (Simple Dynamic Strings).

### Binary Search Tree (Lesson 12)
Complete BST with iterative insertion, recursive inorder traversal for sorted output,
and recursive postorder traversal for cleanup.

### Toy Forth Interpreter (Lessons 23-27, 29)
A stack-based language interpreter built incrementally:
- **Object system**: tagged union with reference counting (5 types: INT, STR, BOOL, LIST, SYMBOL)
- **Lexer/Parser**: tokenizes source into a list of typed objects
- **Execution engine**: walks the token list, pushes literals, dispatches symbols
- **Function table**: supports both native C callbacks and user-defined Forth words
- **Built-in operations**: `+`, `-`, `*`, `dup`, `print`
- Consolidated final version in `toyforth/` (~570 lines of C)

### ZXfy - ZX Spectrum Image Converter (Lessons 30-31)
Converts modern images to ZX Spectrum format using evolutionary optimization. Showcases
external library integration (SDL, libpng), profiling, simulated annealing, and
iterative performance optimization. Source at https://github.com/antirez/zxfy.

---

## Course Arc

The course follows a clear pedagogical progression:

1. **Foundations** (Lessons 01-07): compilation, types, variables, control flow, stack
   memory, recursion
2. **First project** (Lesson 08): Game of Life ties together arrays, loops, abstractions
3. **Pointers** (Lessons 09-11): pointer mechanics, arithmetic, array equivalence,
   practical applications
4. **Dynamic memory and data structures** (Lessons 12-15): malloc/free, BST, linked
   list, file I/O
5. **Advanced type design** (Lessons 16-18): flexible array members, reference counting,
   typedef, opaque types
6. **System programming** (Lessons 19-21): syscalls vs. libc, mmap, unions, bitfields
7. **Higher-order C** (Lesson 22): function pointers and callbacks
8. **Capstone: Forth interpreter** (Lessons 23-27, 29): brings everything together -
   tagged unions, reference counting, dynamic arrays, parsing, function pointers
9. **Variadic functions** (Lesson 28): stdarg.h and API wrapper patterns
10. **Real-world optimization** (Lessons 30-31): profiling, evolutionary algorithms,
    hardware constraints
