# Topics

* Control flow: branch and cycle.
  * if, for, while, do-while, recursion.
* Curly braces define a block
  * You can have a block of one line w/o curly braces, remeber the semicolon.
  * It's possible to write everything on one line.
    * Style comments about this: less code on vertical axis.
    * Do not waste time for style wars be coherent with the project style.
* Blocks
  * I can write a block anywhere.
  * Variable inside a block are visible within a block: variable scope is in the block.
* Print the address of a local variable in the stack: a.k.a a pointer value.
  * In this case the string format for pointers is `%p`.
  * Notice that there's a gap of 4 bytes between variables.
    * Ints are 4 bytes long.
* Use if and goto for doing a loop.
* A "Basic language like" C program.
* If and goto are like a while.
* A while loop.
* How a while loop can be translated to goto-if? Showed.
* Use recursion for looping using if without goto.
  * Cliff-hanger tail call optimization (in a next lesson)
* Recursion uses much more stack memory, be careful.
