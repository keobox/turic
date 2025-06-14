# Topics

* `printf` with int.
* Type promotion to int in the `printf`.
* Use single quote in char assignent: ASCII vale of a char.
* `vi` CTRL-V + CTRL-A Verbatim char.
  * Verbatim char is still an integer under the hood C handles integers even for string representation.
  * char c = 'A' is a C liter char,
* String literal.
* `printf` can print chars passing a number or a char literal.
* Arrays init. Array initialization.
* C strings are array of chars terminated by 0, the NUL terminator.
  * WARNING: it's important having the NUL terminator.
  * See `man ascii` and notice NUL = 000.
* C string literals.
* char array dimension can be removed to obtain a string literal.
* Size of a string in bytes with `sizeof`.
  * IMPORTANT: sizeof operator calculate size at compile time.
* Since strings are array of char I can set one char of it by index.
  * Strings are not immutable.
