# Topics

* Use this lesson to solve some doubts arose in Lesson 16.
* Explain what is `char *str` in a struct: is a pointer to a string.
* If I write `str[20]` now C consider this, in the struct, as an
integer followed by 20 chars. No pointer is present. So, in this case,
there's no equivalence among `char *s` and `char s[]` like in other
contexts.
* Complete the `hexdump` function using the ternary operator.
* A battled tested `hexdump` function from the future.
* Back to `char str[20]` it's just a reference of the end of the struct in fact
has just 8 bytes of offset from the beginning of the struct because `len` is 8 bytes.
  * 20 means there are 20 chars more after `len`.
