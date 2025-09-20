# Topics

* Introducing system calls and standard POSIX.
  * OS X is a certified UNIX.
* Libc has wrappers to system calls plus library stuff.
  * The OS provides services to application process.
  * For example "open a file" is an ask to the OS that
  * returns a number: a file descriptor.
  * `fopen` is a wrapper.
  * We do not want to use this wrapper anymore.
