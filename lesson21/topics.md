# Topics

- Is time to talk about `union`, `bitfield`, `function pointers`.
- A more "regular" way to init a struct.
- `memcopy` is in `string.h` for historical reasons.
- Using an union, now `i` is an integer representation and `a` is
a byte representation, note that if `10` is the first number
then the CPU is `little endian` the least significative byte is
the first.
- Use a larger number to see what happens in the byte representation.
- We used an anonymous `union` that is a `C99` feature`.
- Represents a different layout of the same memory space.
- But what's the purpose of such a thing?
  - Showing the code of `redis/modules/vectors-sets/expr.c`.
  - In a query is possible to filter via expressions like `10 < 50`
  - Is a DSL for redis, the `exprtoken` `typedef` is a "type" of the DSL.
  - It works because a token type cannot be used at the same time, so
only one of the fields is used in an `exprtoken`.
  - So the use case for a `union` is to save memory in case just one
field is used in a `struct`.
- Using `bitfields` in a struct.
