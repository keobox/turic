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
  * <limits.h>
