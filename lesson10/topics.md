# Topics

* Mathematics of pointers.
* Start from lesson 9 code.
* Equivalence of pointer deferencing forms `*p = p[0]`.
* Deferencing works also for reading the pointed value.
* Again on `&` address operator and assign to a pointer.
* Note: all pointers are just numbers, the size of these numbers is the same
of the address BUS of the microprocessor.
* Pointer of pointer and prove a pointer as an address itself.
* Size of pointers with this microprocessor.
* Casting to int.
* In C the an array variable is equivalent to a pointer, hence can be assigned to a pointer.
  * There's no need to use the `&` operator durin assignment.
* Show the pointer/array equivalence for a array of chars and demo pointer mathematics.
  * Print the first 2 chars of a string using the pointer in array notation and using
deferencing plus a mathematic operation on address.
  * This proves that `*(p+1)` moves the pointer by 1 byte (a char).
  * So, type of pointer is important in pointer mathematics.
* Another demo of pointers math: navigating a atring with a pointer to short.
  * This shows that the address changes by the summed number * sizeof of the pointer type.
* Print a string using a char pointer.
