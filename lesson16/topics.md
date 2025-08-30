# Topics

* Summary of the Cliffhanger for reference counting in lesson 13.
  * Initial idea about adding reference counting in a prefixed length string.
* Refactor the initial idea using the `pls` struct.
  * NOTE: that the struct is "naturally aligned".
* Fix free issue.
* Comment: is possible to save 4 bytes in production using `ifdef` to remove
the magic field and the code where the magic field is present.
