# Toy Forth Interpreter - Architecture

A minimal Forth interpreter written in C with zero dependencies beyond libc.
Started by Salvatore Sanfilippo (Antirez) as part of a C programming course.

## Object System

All values in the interpreter share a single `tfobj` struct built around a
discriminated union. A `type` tag selects which branch of the union is active:

| Type constant        | Union field | Description                        |
|----------------------|-------------|------------------------------------|
| `TFOBJ_TYPE_INT`     | `i`         | Integer value                      |
| `TFOBJ_TYPE_STR`     | `str`       | String with pointer and length     |
| `TFOBJ_TYPE_BOOL`    | `i`         | Boolean stored as integer          |
| `TFOBJ_TYPE_LIST`    | `list`      | Dynamic array of `tfobj` pointers  |
| `TFOBJ_TYPE_SYMBOL`  | `str`       | Symbol name (same layout as string)|

This tagged union approach gives a uniform object interface without vtables or
inheritance. Strings are binary-safe: they store an explicit length and use
`memcmp()` for comparison rather than `strcmp()`.

## Memory Management

Objects use manual reference counting. Each `tfobj` has a `refcount` field
initialized to 1 at creation. `retain()` increments it, `release()` decrements
it and calls `freeObject()` when it reaches zero. `freeObject()` handles nested
structures recursively (list elements are released, string buffers are freed).

Allocation wrappers `xmalloc()` and `xrealloc()` abort the program on failure,
eliminating NULL checks at every call site.

## Tokenizer

The `compile()` function is a flat tokenizer that scans the source text
left-to-right and produces a list of token objects. It is not a parser in the
traditional sense: there is no grammar, no precedence, no nesting. Each
iteration of the main loop skips whitespace and then dispatches to either:

- `parseNumber()` - consumes digits (with optional leading `-`) and returns an
  integer object.
- `parseSymbol()` - consumes alphabetic characters and operator characters
  (`+-*/%`) and returns a symbol object.

The result is a flat `TFOBJ_TYPE_LIST` containing integers and symbols in
source order. This simplicity is inherent to Forth: the language has no syntax
beyond whitespace-separated words.

## Stack Machine

Execution follows a stack-based model. The interpreter context (`tfctx`) holds
a data stack (a list object) and a function table. The `exec()` function walks
the compiled token list:

- **Literals** (integers, strings, booleans) are pushed onto the stack.
- **Symbols** are looked up in the function table and executed via `callSymbol()`.

Operators pop their arguments from the stack and push results back. There is no
AST, no expression tree, no variable binding.

## Function Table

Words are registered in a function table stored in the context. Each entry
(`tffuncentry`) holds:

- `name` - a string object with the word name.
- `callback` - a pointer to a C function, or NULL.
- `user_func` - a list representing a user-defined word (not yet implemented).

Lookup is a linear scan comparing names with `compareStringObject()`.

`registerCFunction()` binds a C function to a word name. If the name already
exists, the entry is replaced. The `basicMathFunctions` callback handles `+`,
`-`, and `*` by switching on the first character of the word name, so a single
C function serves multiple operators.

## Standard Library

### Arithmetic: `+`, `-`, `*`

Pop two integers, apply the operation, push the result. All handled by a single
`basicMathFunctions` callback that dispatches on `name[0]`.

### Stack manipulation: `dup`

Peeks at the top of stack, retains it, and pushes a second reference.

### Output: `print`

Pops the top of stack, prints it using `printObject()` followed by a newline,
and releases the object. `printObject()` handles all types recursively (lists
print as `[a b c]`, strings as `"s"`, integers as decimal).

## Execution Flow

1. `main()` reads the source file into memory.
2. `compile()` tokenizes the source into a list of objects.
3. The compiled list is printed for debugging.
4. `createContext()` initializes the stack and registers built-in words.
5. `exec()` walks the token list and evaluates it.
6. The final stack contents are printed.

## File Structure

Everything lives in a single `toyforth.c` file with sections separated by
banner comments:

- Data structures and type definitions
- Allocation wrappers
- Object creation and lifecycle (create, free, retain, release)
- String and list operations
- Tokenizer
- Execution engine and context management
- Standard library functions
- Main
