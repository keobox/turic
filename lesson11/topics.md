# Topics

* Again about the short pointer accessing a string.
  * Clarify using an array of chars: a sequence of bytes.
* Base 2 numbers: binary representation.
  * Multiply by 2 is shift a bit to the left.
  * This to explain why there's a 256 in numeric conversion.
  * Is because during conversion the most significative byte is moved by
one position and this is equivalent to move 8 bit by 8 positions, so
8 positions corresponds to multiply by 2^8 = 256.
* Back to write something like a printf using a char pointer.
* Clarify a doubt: the '0' character is not the 0 number!
* Inserting a real 0, using octal, in the array of char so that while stops earlier.
* Implementing a safe string type: prefixed length strings.
* Back to Game of Life program in Lesson 8.
  * Remove the code duplication thanks to pointers.
