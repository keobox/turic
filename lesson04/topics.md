# Topics

* Integer types
  * In other languages Integers are the same on any hardware.
  * In C the type can change on different hardware.
* How is big an integer? We don't know: `sizeof` usage.
  * There will be a warning because `sizeof` returns an unsigned long.
  * Can be solved using a `cast`.
  * Or, correcly use the long unsigned format in printf.
* What fits into 4 bytes?
  * 2^32 integers
  * Is possible to use `bc` command for calculations
  * 0 -- 4294967295 for unsigned int [0 -- (2^32 -1)]
  * -2147483648 -- 2147483647 for signed int  [-2^32/2 -- (2^32/2 - 1)] so [-2^31 -- (2^31 - 1)]
* There's a way to know the ranges?
  * `<limits.h>`
* The story is that the C standard does not guarantees type sizes.
  * But on modern 32 or 64 bits HW there's a kind of standardization.
  * In the 99% of cases the size are in `hello_world_sizes.c`.
  * The long type is the `word` size of the HW architecture.
  * Warning: do not use `int` to save memory addresses in 64 bit HW architecture.
* The `<stdint.h>` contains C-99 "new" standard types: `uint64_t`, `int64_t`, `size_t`, `intptr_t`, `uintptr_t`.
  * The `ptr` types assure a memory address is containable.
* Back to old hello world.
* Dissertation about function calling and indentation.
* In C buffer flush `fflush` is automatic after a new line.
* Strings in C are sequences of `char`.
* Sequence of control VT100 in the hello world: [H means go home, first char of the terminal window.
