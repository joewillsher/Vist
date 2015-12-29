
# TODO


* Method & property parsing

* Name mangling

* Struct IR Gen
    - Properties and padding (incl improving current equal-width impl)
    - Method implementation -- sema pass getting info about functions and associating them with the object
    - Concepts and dynamic methods -- need to work out type model
    - Reference semantics implemented
    - Initialisers

* Arrays
    - Implement append by hooking into a compiler-magic function to modify array buffer size
    - Use sema pass to work out what can be statically sized, otherise move to the heap
    - Store arr size next to head ptr at runtime

* Standard library
    - need to invesitgate how I can let this interact with the compiler
    - write stdlib int and array types

* Strings

* Make functions first class objects
    - Currying
    - Partial application of functions

* Look into guard statements. Haskell:

```haskell
factorial n
    | n < 2     = 1
    | otherwise = n * factorial (n - 1)
```
