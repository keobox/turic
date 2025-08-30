# Topics

* Summary of the Cliffhanger for reference counting in lesson 13.
  * Initial idea about adding reference counting in a prefixed length string.
* Refactor the initial idea using the `pls` struct.
  * NOTE: that the struct is "naturally aligned".
  * NOTE: the `char str[]` field in the `pls` struct is a *Flexible array member*
    * This was introduced in C99.
    * Rules:
      * Must be the last member of the struct.
      * Variable Length: Unlike a regular array declaration like `char str[10]`, this doesn't allocate a fixed amount of space. Instead, it allows the struct to have a variable-length array at the end.
      * Zero Size in Struct: The flexible array member itself takes up zero bytes in the struct size calculation. So sizeof(struct pls) only includes the len and refcount fields.
      * So the size is 8 bytes.
* Fix free issue.
* Comment: is possible to save 4 bytes in production using `ifdef` to remove
the magic field and the code where the magic field is present.
