# Topics

* Introducing system calls and standard POSIX.
  * OS X is a certified UNIX.
* Libc has wrappers to system calls plus library stuff.
  * The OS provides services to application process.
  * For example "open a file" is an ask to the OS that
  * returns a number: a file descriptor.
  * `fopen` is a wrapper.
  * We do not want to use this wrapper anymore.
* The UNIX, POSIX complean system call is `open`.
  * `man 2 open`.
  * Explanation of more important flags to open a file, like `O_RDONLY` etc..
  * Flags are a bitmask.
* Introducing `errno` and explain what `perror` does.
  * `errno` is a global, thread-local variable that contains the occurred error code.
  * `man 2 open` at the end of the man all the possible error code about open
are listed.
  * Prove that a failed open cause errono to be equal to `ENOENT`.
  * Prove that when open succeded errno is zero.
  * the `perror` function translates the errno value in a string.
`Unable to open the file: No such file or directory`
