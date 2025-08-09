# Topics

* Recap of prefixed strings and interoperalability with c-strings.
  * Iteroperability function `ps_getc`.
* Increment the length size to 4 bytes.
  * `#include <stdint.h>` includes integer type like `uint32_t` `int32_t` etc.
  * In this case the max length is 2^32 = 4GB.
* Write `ps_len` to return string length in O(1): by reading the header.
* So we resolved an interesting problem using metadata (the length of string)
behind a pointer.
* Antirez then showed that the new allocators should crash the program in case of
double free but there's no guarantee.
