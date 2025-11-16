# Topics

- Toy Forth part 4.
  - Plan: implement `exec`.
- In the last question we implemented the parser.
- Comments about the symbols:
  - "quoting" the symbols is necessary in cases when
  we want to push a symbol on the stack and not execute it
  for example `print is-function-valid?` we want just push
  `is-function-valid?` on the stack and not execute right away.
- Add the raw symbol quoting I did not added in Lesson 25.
- In case we want implement a real quoting we should add a `quote`
field in case of strings in `tfobj`.
- Remove "quoting" and fix a litte bug in `print_object`.
- Digression: explain `assert`.
- Implement `xrealloc` as per comments in YT.
- Implement `createContext` which is a container for a list
that is our programming language. For now is just a list
but can be more.
- Initial implementation of `exec`.
