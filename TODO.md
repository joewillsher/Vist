
# TODO


* Method & property parsing

* Semantic analysis
    - Type and variable/function reliability checking
    - Adding information into AST about the types it is going to lower to -- move a lot of the checks from IRGen into this
    - Interface gen (for linking files) (after Sema pass)

* Struct IR Gen
    - Properties and padding (incl improving current equal-width impl)
    - Method implementation -- sema pass getting info about functions and associating them with the object
    - Concepts and dynamic methods -- need to work out type model

* Arrays
    - Implement append by hooking into a compiler-magic function to modify array buffer size
    - Use sema pass to work out what can be statically sized, otherise move to the heap
    - Store arr size next to head ptr at runtime

* Standard library
    - need to invesitgate how I can let this interact with the compiler
    - write stdlib int and array types

* Strings



