# Topics
- Part 2 of the Toy Forth interpreter.
- `tfparser` `struct` will be used during parsing where `prg` would
be the beginning of the program and `p` the next token.
- `tfctx` in this case the context is just a stack.
  - Why the stack is the same type of the program object? (in this
  case the program is a list).
    - For semplicity.
  - Why the lists that represent the program is an array?
    - (We are talking about the `ele` field).
    - The linked list seems ideal for this use case, but is
    not cache friendly and uses more memory.
    - We can add `alloc_len` under `len` and over allocate
    more room in the array. And when `len` is equal to
    `alloc_len` use `realloc` to add power of 2 more
    elements. When the number decrese, do not realloc but
    leave the same memory, in this way the "amortized" append
    time is O(1), but I have strict O(1) access time and better
    locality.
    - My comment: basically we are using an array list.
- Implement file size retrieval.
- Comment on "Cancatenative programming language.
- Example [Joy Language](https://en.wikipedia.org/wiki/Joy_(programming_language)
- A Joy interpreter implementation [example](https://wiki.tcl-lang.org/page/A+Joy+implementation+in+Tcl)
- A comment about the implementation of local variables without
changing the language's semantics.
  - Added and example using something like tuples in `program.tf`.
  - Added a `swap` implementation using local variables.
