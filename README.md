#README #

##About
A functional, statically typed programming language using LLVM, inspired by Swift, Haskell, and Rust. Vist has a friendly & low weight syntax, and modern type system with a focus on generics and protocols.


##Installing
To install, run

``` bash
git clone https://github.com/joewillsher/Vist.git
cd vist
./build
``` 

This downloads the LLVM libraries, builds the libvist standard library and runtime and installs the compiler. To use it call `vist` from the command line, use `-h` to see options.

To develop in Xcode, go to ‘Edit Scheme’ (⌘<) and set the *arguments* to `-O -verbose -preserve example.vist` and under *Options* set the ‘Custom Working Directory’ to `$(SRCROOT)/RUN`.


##Architecture overview
Vist is a strongly typed language which compiles to [LLVM’s](https://en.wikipedia.org/wiki/LLVM#LLVM_Intermediate_Representation) [IR](http://llvm.org/docs/LangRef.html)—a high level (so mostly architecture agnostic), typed, [SSA](https://en.wikipedia.org/wiki/Static_single_assignment_form) assembly language. Vist’s compiler structure was inspired by the implementation of other languages such as [Rust](https://github.com/rust-lang/rust) and particularly [Swift](https://github.com/apple/swift).

The compile process involves transforming the source code from one representation to another—the text is [lexed](https://en.wikipedia.org/wiki/Lexical_analysis) into a series of tokens, which is [parsed](https://en.wikipedia.org/wiki/Parsing#Computer_languages) to form the [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree). The [semantic analysis](https://en.wikibooks.org/wiki/Compiler_Construction/Semantic_Analysis) pass then walks the tree, adding type information, and then to generate the IR code.

The [lexing](Vist/Lexer/Lexer.swift) separates Vist’s keywords and characters into a stream of tokens. [Parsing](Vist/AST/Parser.swift) extracts the program’s meaning, and constructs the [AST](Vist/AST/Expr.swift). The [sema](Vist/Sema/TypeProvider.swift) pass type checks the source and does other static checks, like making sure variables are declared before they’re used. The [IRGen](Vist/IRGen/IRGen.swift) phase then creates the LLVM IR code, which is optimised and compiled.


##The Language
Function definitions require a type signature and can label the arguments using names in parentheses before the block
```swift
func add :: Int Int -> Int = (a b) {
    return a + b
}
```
Functions are given default labels in no argument labels are provided, and if their body is only one expression you may define its body in a *do block*
```swift
func myPrint :: Int = do print $0
```

Other statements in Vist support these *do blocks*
```swift
func factorial :: Int -> Int = (a) do
    if a <= 1 do
        return 1
    else do
        return a * factorial a - 1
```

Constants are declared using `let`, and variables using `var`
```swift
let constant = 100
var variable = 10
variable = 3
```

Functions are called by writing the argument list after the function name. To disambiguate other function calls as parameters, wrap them in parentheses. Operators also take precedence over functions in parameter lists
```swift
print constant * variable		// > 300
print (add 10 (factorial 10))	// > 3628810
```

Vist supports declaring types with *stored properties* and *methods*
```swift
type Foo {
    var a: Int
    let b: Int
    
    func sumAndTimesBy :: Int -> Int = do 
        return $0 * (a + b)
}
```

Vist automatically constructs a *memberwise initialiser* for a type. This is a constructor function which takes a list of parameters in the order of the type’s stored properties
```swift
let fooInstance = Foo 1 4
let sum = fooInstance.sumAndTimesBy 2
print sum // > 10
```

Vist’s type system is based around *concepts* and *generics*. Concepts describe what a type can do—its properties and methods.
```swift
concept TwoInts {
    var a: Int, b: Int
}
```

A function can now take any `TwoInts` object as a parameter—here the concept is being used *existentially* [(i.e. it isn’t used as a constraint, but a type)](../Posts/Concepts_and_runtime.md).
```swift
func sum :: TwoInts Int -> Int = (x y) do
    return x.a + y + x.b
```

Generics could be used instead, allowing us to statically dispatch the property lookups and enforcing both arguments are the same type. We can also use concepts as constraints
```swift
func sum (T | TwoInts) :: T T -> Int = (u v) do
	return u.a + v.b
```

This `sum` function is generic over any type that models `TwoInts`, called `T`.


##Writing
I am writing about compilers and the development of Vist.

- [Abstraction & Optimisation](Posts/Abstraction_and_Optimisation.md)


