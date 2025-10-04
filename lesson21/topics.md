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
- If I set `f.a = 16` I will get a warning and the result is an overflow of
a number of 4 bits so `f.a = 0`, `f.a = 17` will overflow to 1.
- The is a rule in C incrementing an `unsigned` type pass it's limit
make it return to 0: is a silent  overflow.
- If the type is `signed` the overflow is an `undefined behaviour`, so is
worse of the `unsigned` case.
- Why using `bitfields`?
  - Save memory.
  - Use in packets representation of a netowrk protocol.
  - Use in a header of a file type.
- Warning: the bitfields are not well standardized, and depends of endianess
there are not clear guarantees and in general this is a portability problem.
- Showed the IP packet struct https://sites.uclouvain.be/SystInfo/usr/include/netinet/ip.h.html
  - `struct iphdr`.
```c
struct iphdr
  {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int ihl:4;
    unsigned int version:4;
#elif __BYTE_ORDER == __BIG_ENDIAN
    unsigned int version:4;
    unsigned int ihl:4;
#else
# error        "Please fix <bits/endian.h>"
#endif
    u_int8_t tos;
    u_int16_t tot_len;
    u_int16_t id;
    u_int16_t frag_off;
    u_int8_t ttl;
    u_int8_t protocol;
    u_int16_t check;
    u_int32_t saddr;
    u_int32_t daddr;
    /*The options start here. */
  };
```
- Showed the code of `redis/src/server.h` `redisObject` is using bitfields.
```c
struct redisObject {
    unsigned type:4;
    unsigned encoding:4;
    unsigned lru:LRU_BITS; /* LRU time (relative to global lru_clock) or
                            * LFU data (least significant 8 bits frequency
                            * and most significant 16 bits access time). */
    unsigned iskvobj : 1;   /* 1 if this struct serves as a kvobj base */
    unsigned expirable : 1; /* 1 if this key has expiration time attached.
                             * If set, then this object is of type kvobj */
    unsigned refcount : OBJ_REFCOUNT_BITS;
    void *ptr;
};
```
- NOTE: the `unsigned` fields defaults to `unsigned int`.
  - Even if the `type` field is `int` the bitfield notation applies
to the overall struct, does not mean that, for example `type`
is 32 bits and use just 4 so the bitfields are instructions
about how to pack the fields in a 32 bits contiguous space.
