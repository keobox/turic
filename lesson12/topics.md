# Topics

* Recall that the safe string type: prefixed string, implemented in Lesson 11
is a Pascal style string.
  * In that implementation the first byte contain the length of the string.
* We will implement a prefixed string in C in this lesson.
  * This will be done in two ways, one has limitations.
  * This is done to highlight some shortcomings (and hopefully how to
deal with these).
  * The first implementation uses a char array on stack.
* Show that the implementation can work with 0 in the buffer, 0 is no more a special
byte value.
* Where is the problem?
  * What if I want many strings?
  * Should I create many buffers on stack? Or use global buffers?
* To solve this we will update the code.
* Enter malloc and free.
  * `man malloc`
* My comment: `ps_free` is missing.
* Defensive programming.
  * What if my string is used with printf?
  * Fix that at least for not to crash.
* Implement a prefixed string to c-string conversion.
* `free` the memory, now the program is correct.

# Appendix 01
* After a discussion on LinkedIn about programming interviews Antirez decided to clarify
what is the his way to face tech interviews by coding a Binary Search Tree from scratch
by using the single idea that the node on the left has a smaller
value and node on the right has a bigger value respect to the current node.
* My comment: this is a form of Live coding and I don't like this that much.
I'd prefer to ask a simple problem that can be solved with a specific data structure and
the candidate should defend why she/he pick that structure and the trade off of chosing it.
* Highlight: `sizeof(*new)` the `*` operator give the size to the pointed struct.
* Skipping `malloc` error handling for brevity.
* The second main idea is that a BST can be navigated recursively this can be used to print
sorted values, ascending.
* My comment: the `print_sorted` function is an "Inorder tree walk" and the idea is first go left the print (visit) then go right.
* Great trick by Antirez! Use Gemini as code reviewer!
  * This is what Gemini spotted.
  * Not checking for same `val` so value duplication allowed on the left,
but this was more a design choice.
  * Missing `free_tree` function: a recursive approach can be used also in this case.
  * This can be done with a "Postorder" tree walk.
  * For completeness in the "Preorder" tree walk, the root node gets visited first, followed by left and right subtrees.
