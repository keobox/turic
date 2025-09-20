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
* Our program runs in `user space` (and in a virtual memory) so has
his own address space, but the kernel, that runs in `kernel space`,
has a way to take a pointer in `user space` and copy into it
something that is in `kernel space`.
  * (Wikipedia)[https://en.wikipedia.org/wiki/User_space_and_kernel_space]
  * The system call that does this is `read`.
  * `man 2 read`.
  * `read` returns `ssize_t` that is the signed version of `size_t`,
because it can return -1, like all system calls.
  * The opher paramenter are:
    * The file descriptor, a pointer to the memory to write into and
`nbyte` is the maximum nember of bytes to read, but there's no guarantee
that this exact number of bytes will be read, since `read` can operate
on a TCP socket, not only a file.
* The system call to write is `write`.
  * `man 2 write`.
  * `write` could be used to print stuff in standard output `stdout`
but this can be overkill.
* HOMEWORK: read this man pages:
  * `man 2 read`
  * `man 2 write`
  * `man 2 open`
  * Better to read the `Linux` man pages on web.
