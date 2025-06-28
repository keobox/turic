# Topics

* Recursion
  * Using `goto` for "Tail Call Optimization", or "Tail recursion".
  * Is possible to do this only if the function calls just itself at the end.
  * Notice that in the optimized case there's no extra stack usage.
* While.
* For. It's a equivalent to `while`, it's just "syntactic sugar".
  * Since the initialization part is already done we can skip it and leave just the `;`.
  * Skip the condition part and use `if` and `break` in the for loop.
  * Transform a for loop in a while loop. Notice that the condition is negated respect before.
* Go back to infinite while loop instead of infinite for loop.
* Scoped variable in a for loop.
* Use an array in the for loop.
  * Show an example where a scoped variable is not convenient, in case the checks are outside the loop.
* Brief description of `do-while` but no demo.
* Switch.
  * The only difference with if is that if break is not present we go in the next case.
  * Is not possible adding a scoped variable in a `case`. `case` is like a goto label.
  * By adding a block is possible to declare a scoped variable in a `case` statement.
* Showed that switch use is not that much in a real codebase.
* Showed a recursive function to resolve `globbing` in file names: is recursive in the `'*'` `case`.
