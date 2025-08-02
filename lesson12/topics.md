# Topics

* Recall that the safe string type: prefixed string, implemented in Lesson 11
is a Pascal style string.
  * In that implementation the first byte contain the length of the string.
* We will implement a prefixed string in C in this lesson.
  * This will be done in two ways, one has limitations.
  * This is done to highlight some shortcomings (and hopefully how to
deal with these).
  * The first implementation uses a char array on stack.
* Show that the implementation can work with 0 in the buffer, 0 is no more a special
byte value.
* Where is the problem?
  * What if I want many strings?
  * Should I create many buffers on stack? Or use global buffers?
* To solve this we will update the code.
* Enter malloc and free.
  * `man malloc`
* My comment: `ps_free` is missing.
