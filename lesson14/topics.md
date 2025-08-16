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
  * No, the dimension is 12 because of the memory alignment, every field's address is
a multiple of four so there are 3 bytes of padding.
  * What if we add the littler `char` field at the end of the `struct`, will the size be 9?
  * No, is still 12 because the `struct` has the guarantee that is aligned to the greater
field among its fields.
    * This guarantee is necessary because I can declare an array of structures.
* An example of a well designed `struct` with no holes in it. The size is 12.
  * But in case we create holes the memory aligment on the bigger field will happen.
Now `struct` size is 20 due to memory aligment.
* In reality is possible to avoid memory aligment problem via `bitfields` and `packed struct`,
we will talk about this advanced topics later.
* How a `struct` variable works.
* How a `struct` pointer variable works.
* Comment: in case of pointers the field access uses `->` instead of `.` to enhance readability:
make explicit the fact that we are dealing with a pointer to `struct` variable instead of simple
`struct` variable, even if a compiler could infer this.
