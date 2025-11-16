# Topics

- Toy Forth part 4.
  - Plan: implement `exec`.
- In the last question we implemented the parser.
- Comments about the symbols:
  - "quoting" the symbols is necessary in cases when
  we want to push a symbol on the stack and not execute it
  for example `print is-function-valid?` we want just push
  `is-function-valid?` on the stack and not execute right away.
