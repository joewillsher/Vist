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
Vist is a high level strongly typed language aimed at being concise and flexible yet safe. The Vist code compiles to VIR, a high level intermediary representation which will eventually allow optimisations specific to Vist’s semantics and its type system’s guarantees. 

The VIR is generated from the parsed and type checked AST; the VIR is lowered to LLVM IR which is used to generate the program.  

The Vist compiler is mainly implemented in Swift but much of the functionality is written in vist. All standard types—like ints, floats, bools, and ranges—are implemented in the standard library. The code is still lowered to performant machine code however, as the standard library is able to access native CPU instructions and types and be optimised heavily.


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

Vist supports declaring types with *stored properties*, *methods*, and *initialisers*. Types have value semantics by default, promoting safety and speed, but they can be marked as being a `ref type` where the memory is managed using automatic reference counting.
```swift
type Foo {
    var a: Int
    let b: Int
    
    func sumAndTimesBy :: Int -> Int = do 
        return $0 * (a + b)
}
```

Vist’s type system is based around *concepts* and *generics*. Concepts describe what a type can do—its properties and methods. Concepts can be used as constraints or existentially as types.
```swift
concept TwoInts {
    var a: Int, b: Int
}

func sum :: TwoInts Int -> Int = (x y) do
    return x.a + y + x.b

func sum (T | TwoInts) :: T T -> Int = (u v) do
	return u.a + v.b
```




