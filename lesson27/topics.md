# Topics

- Toy Forth part 5.
- Long coding session to implement function registration.
- At line 295 there's a `#if 0` with example code of
what will be doing next time.
- From a comment on YT: why not using `strcmp` for string comparison?
  - Because `strcmp` does not handle zero. Is not binary safe.
  - `memcmp` is binary safe.
