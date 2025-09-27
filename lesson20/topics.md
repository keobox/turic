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
