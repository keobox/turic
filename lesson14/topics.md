# Topics

* Brief recap of Lesson 13.
  * Reference counting idea recap.
  * Cliffhanger recap: use a struct as Prefixed Length header: see `struct.c`.
* To review C structs write a program for fractions handling.
* To make room for 2 ints numerator and denominator I could use a `malloc`.
* Add basic function for frations handling.
* Refactor `set_fraction` to `create_fraction`.
* Write a fraction semplification function.
* Is possible to refactor using a struct: an aggregated data type.
* But before a digression about `struct' dimension.
  * The `struct` dimension is 8 bytes as expected.
  * What is we add an unsigned byte before the 2 int fields? Is the dimension 9 bytes?
