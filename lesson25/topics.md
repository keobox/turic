# Topics

- This is part 3 of the `toyforth.c` Forth interpreter project.
- Refactor using a `switch` statement.
- Adding the int case and refactor `print_object` to use recursion.
- Fix a bug that prevents to use `-` as symbol in `compile`.
- Add `parseSymbol`.
  - Fix the problem I noted before on `createStringObject`.
- Cliffhanger for next time:
  - We are now ready to implement `exec` since we can
  implement print using `print_obejct`.
  - Numbers and symbols are enough for execute something
  - NOTE: using recursive print we can print nested
  lists easily.
