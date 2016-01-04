
# TODO

* Strings

* Struct IR Gen
    - Implicit initialisers
    - Method implementation -- sema pass getting info about functions and associating them with the object
    - Concepts and dynamic methods -- need to work out type model
    - Reference semantics implemented
    - Initialiser taking pointer to unallocated mem and initalising it, currently it returns an initialised instance
    
* AST context object to help type inference when in sema

* Move more checks at IR level to sema pass

* Arrays
    - Implement append by hooking into a compiler-magic function to modify array buffer size
    - Use sema pass to work out what can be statically sized, otherise move to the heap
    - Store arr size next to head ptr at runtime

* Standard library
    - need to invesitgate how I can let this interact with the compiler
    - write stdlib int and array types

* Memory management

* Make functions first class objects
    - Currying & partial application of functions, needs to reference captured objects on the heap
    - https://en.wikipedia.org/wiki/Closure_(computer_programming)#Implementation_and_theory

* Look into guard statements. Like Haskell:

```haskell
factorial n
    | n < 2     = 1
    | otherwise = n * factorial (n - 1)
```
