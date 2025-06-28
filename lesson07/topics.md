# Topics

* Recursion
  * Using `goto` for "Tail Call Optimization", or "Tail recursion".
  * Is possible to do this only if the function calls just itself at the end.
  * Notice that in the optimized case there's no extra stack usage.
* While.
* For. It's a equivalent to `while`, it's just "syntactic sugar".
  * Since the initialization part is already done we can skip it and leave just the `;`.
  * Skip the condition part and use `if` and `break` in the for loop.
