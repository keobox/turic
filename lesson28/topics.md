# Topics
- Variadic functions, meaning having function with a variable number of arguments.
- This is a necessary step for error handling in the toy forth interpreter.
- See `man va_start`.
- The "object" to access "variable arguments" is `va_list` and there are 4 functions
to manipulate it.
- A variadic function is defined like this `foo(char *fmt, ...`) using "ellipses".
- Inside the function is necessary to use the "access functions" like `va_start`.
- Typically there are `va_list` variables to access these variable handling objects.
- NOTE: the ellipses is a C syntax, but variable handling is not.
- `va_start va_arg va_copy va_end` are macros in `sdtarg.h`.
- NOTE: `last` is the last "normal" argument before the variable arguments.
- Why we have to specify the type of a variable?
  - No warnings in compile pass because macros will expand a wrong return type.
  - In general C has not a way to know the type at runtime and compile time,
  can't infer from type of argument passed.
- What if I want to call a variadic function that calls another variadic function?
- `man 3 printf`.
- There are "kind" of printf that start with "v" suffix, like `vprintf` that takes
a `va_list` as final argument.
- Now we have the knoledge for implementing the "set context error for toyforth".
