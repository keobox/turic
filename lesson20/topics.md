# Topics

* When is convenient use the Libc API
instead of System Calls like `open`?
  * To answer is better to clarify what is the **role**
of the Libc I/O abstraction.
  * To show that see `stdio3.c`.
  * `unistd.h` is necessary for the sleep sys call.
  * `sleep` works because the kernel is multi-tasking and
preentive (?) many process can be scheduled to run by the
scheduler.
  * This is why a process on I/O with waiting on a `read`
gets paused until there's actually something to read.
  * Example, if we add a `printf` before the sleep
something strange happens.
  * `sleep` seems executed before the `printf` why?
  * This is because Libc I/O abstraction implements
`buffering`.
  * Note: when I call a sys call there's a data exchange
with the Kernel space, in general calling a sys call
is expensive. Even if in modern systems this is mitigated.
  * So Libc tries to optimize this situation with `buffering`.
  * We can use `putchar` but buffering is still there.
  * So we avoid to call a sys call for every char.
  * If we use `write` sys call for every char the buffering
is avoided.
* NOTE: the '\n' char has the property to trigger a "flush"
of the buffer in Libc, so we can have the same behaviour of
using a `write` with `putchar` Libc function.
  * Or we can use the `fflush` Libc function to force the
flush of the buffer.
* Add a nice effect to `stdio3.c`.
* So, in general program written by Libc are more performant,
because of the buffering.
  * But there are cases where you want to write an ad hoc
buffering to be even more efficient, in the case use the
sys calls, but you have to handle your ad hoc buffering.
* This buffering is present also during reading from a file.
* For example the `fgets` Libc function is capable to read
from a text file line per line, and flush the buffer when
a newline is hit.
  * So a trivial usage of `read` to implent this "line read"
is possible to be much worse than `fgets`.
* Another thing to consider is **portability** a program
that uses only Libc can be compiled on many platform if
these platforms have an `ANSI C` compiler.
* Warning: often, for doing advanced stuff is necessary to use
sys calls.
* We said before that a process can communicate with outside
using the sys calls of the kernel.
  * But there is has another possibility to communicate with the
outside: using the fact a process has the capability to read and
write memory.
  * This is still used in microcontrollers to control memory
mapped devices.
  * To elaborate this, in UNIX there's a POSIX sys call: `mmap`
that can map the content of a file in the memory space of
the process. So I can read the content via a pointer.
  * `man mmap`.
  * Change `stdio3.c` to load itself into a memory mapped file.
* Now change the code in `stdio3.c` to access the file just like
we access and array in memory.
* The use of `mmap` is the fasted possible way to access files.
* Basically with mmap a page of memory, with file content, is
copied into a process' memory page.
* Warning: a process's memory page can be written out to a file
using a different sys call.
  * So, use use case is: I can do a lot of operations in this
memory mapped file without using sys calls or the general purpose
buffering system of Libc, then write just once the file with
just one call to a sys call.
* An idea to use `mmap`: write a memory mapped `grep` command.
