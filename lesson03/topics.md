# Topics

* Function with just side effect. A procedure.
* Local variable re-created.
* Global variable.
* Static variable, a global variable that is seen only in a function.
* Static and global variables are not thread safe (needs mutexes).
* Passing by value.
* Use the return value of a function.
* Float primitive type.
* C is dangerous. Warnings can be runtime issues.
* Why signal a problem in "double" instead of "float" in format string.
  * Study the floating point representation of number.
* C language as too much primitive types so Variadic arguments function like
`printf` promote a number to the higher type of a class so `float` are promoted
to `double` and `short` is promoted to int. This is done before printing.
  * It's important to understand the presence of this implicit conversions.
* The char type.
* Char type overflow with warning. It's like goes on the last negative side.
Prints -128. It's a wrapping due overflow.
  * This wrapping is guranteed just for `unsigned` types but it's an undefined behaviour
for the signed types, so is more dangerous. It's printing -128 but anything can happen.
* Implicit promotion `char` to `int` in expressions.
* Legal overflow of an unsigned char. No warnings here.
