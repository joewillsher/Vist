
# TODO

* Standard library
    - write stdlib array type
    - Strings

* Structs
    - Initialisers
        - Generate one which does that but including objects with initial values
    - Generics & concepts (as constriants and existentials)
    - Reference semantics implemented -- using `ref type` or `ref let a = b`??
    
* AST context object to help type inference when in sema

* Move more checks at IR level to sema pass

* Loops and inlining fixes
    - currently crashing in loops or late stage tail-recursion-removed functions

* Compile pipeling in process (in c++)

* Multiple file compiliation
    - linking AST & interface gen
    - Multi thread IRGen







* Arrays
    - Implement append by hooking into a compiler-magic function to modify array buffer size
    - Use sema pass to work out what can be statically sized, otherise move to the heap
    - Store arr size next to head ptr at runtime

* Memory management on the heap

* Make functions first class objects
    - Currying & partial application of functions, needs to reference captured objects on the heap
    - https://en.wikipedia.org/wiki/Closure_(computer_programming)#Implementation_and_theory

* Look into guard statements & enums. Like Haskell:

https://wiki.haskell.org/Introduction

```haskell
factorial n
    | n < 2     = 1
    | otherwise = n * factorial (n - 1)

data Token
    = Spc Int                     -- horizontal space of positive length
    | EoL                         -- line break
    | Sym String                  -- one contiguous nonspace symbol
    | Grp String [Token] String   -- a valid bracketing of more tokens
    | Sub [Token]                 -- a substructure found by parsing
    deriving (Eq, Ord)            -- anything <= EoL is whitespace

grep printf Foo.c | wc

```

Haskell:
    - Function call syntax `foo 1 2`
    - Pipe operator to chain function calls
    = Need to get curried functions working
    - map and filter functions

