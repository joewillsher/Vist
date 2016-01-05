
# TODO

* Standard library
    - Let the stdlib use native types & functions
        - use LLVM.Int64 to annotate to the compiler when to generate native LLVM types
        - use LLVM.add_i64_i64 to annotate when to use builtin functions
        - the compiler then sees substitutes these with their native counterparts
    - To make literals look into stdlib
        - Int has an initialiser that takes LLVM.Int64, give the compiler special knowlege of this
        - The compiler wraps any literals in this initaliser
    - write stdlib int and array types

* Operators

* Structs
    - Implicit initialisers
    - Generics & concepts (as constriants and existentials)
    - Reference semantics implemented
    - Initialiser taking pointer to unallocated mem and initalising it, currently it returns an initialised instance

* Strings
    
* AST context object to help type inference when in sema

* Move more checks at IR level to sema pass

* Arrays
    - Implement append by hooking into a compiler-magic function to modify array buffer size
    - Use sema pass to work out what can be statically sized, otherise move to the heap
    - Store arr size next to head ptr at runtime

* Memory management on the heap

* Make functions first class objects
    - Currying & partial application of functions, needs to reference captured objects on the heap
    - https://en.wikipedia.org/wiki/Closure_(computer_programming)#Implementation_and_theory

* Look into guard statements. Like Haskell:

```haskell
factorial n
    | n < 2     = 1
    | otherwise = n * factorial (n - 1)
```
