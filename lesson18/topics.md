# Topics

* The prefixed length string is work is finished.
* Introducing `typedef`.
* `typedef` of a struct.
* `typedef` of a pointer of a struct that is a `typedef` itself.
  * This `typedef` of a pointer of a struct aliased with a `typedef`
is interesting because it open the possibility to declare an opaque type:
expose just the pointer (or handle) of an object.
* An example of this `typedef` usage is the `fopen` function to open a file:
we don't know what exactly is the `FILE *` type but we can operate on it.
* `fread` read from a file. Is not a great API example at least nowadays.
  * man `fread`.
* Read and analize `stdio1.c` file itself.
  * Not much different from `hexdump -C stdio1.c`.
* Can we be able to implement something similar to `fread`?
  * man `fopen`. All the OS system calls can be used to implement an IO library.
  * In the next lesson we will implement this library to learn more.
  * This will be a real programming experience.
