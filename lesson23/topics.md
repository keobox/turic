# Topics

- Today we will do something not trivial.
- A Forth interpreter: a language based on stack.
  - Example`5 5 +` has result `10`.
  - Stack languages are diveded in `words`.
  - A program is basically a list of `words`.
  - Another example `5 dup +` result is `10` again.
  - How to do `if` or `for`?
    - Using sub-programs
    - Example of `if`: `[dup *] [dup +] [10 20 <] if`
    - Better for comprehension:
```
[10 20 <]
  [dup *]
  [dup +] ifelse
```
- Comment about `argv[0]` containing the invoked command name.
