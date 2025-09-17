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
