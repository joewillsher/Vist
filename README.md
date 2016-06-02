#README #

##About
A functional, statically typed programming language using LLVM, inspired by Swift, Haskell, and Rust. Vist has a friendly & low weight syntax, and modern type system with a focus on generics and protocols.


##Installing
Vist is is written in Swift 3.0 and compiles under the most recent [Swift 3.0 Preview 1 release, available here](https://swift.org/download/)

To install, run

``` bash
git clone https://github.com/joewillsher/Vist.git
cd vist
./utils/build
``` 

This downloads the LLVM libraries, builds the libvist standard library and runtime and installs the compiler. To use it call `vist` from the command line, use `-h` to see options.

To develop in Xcode, go to ‘Edit Scheme’ (⌘<) and under *Options* set the ‘Custom Working Directory’ to the location of your test files, and under *arguments* include `-verbose -preserve` to log and save the compiler temp files.


##The Language
Vist’s syntax is lightweight; a hello world is as simple as

```swift
print "Hello Vist!"
```

```swift
func factorial :: Int -> Int = (n) do
    if n <= 1 do return 1
    else do return n * factorial n - 1
```


##Architecture

Vist is a high level and strongly typed language aimed at being concise, flexible, and safe. The Vist code compiles to VIR, a high level intermediary representation which will allows optimisations specific to Vist’s semantics and its type system’s guarantees. Vist code is lowered to native, performant machine code and provides efficient abstractions.

The Vist compiler is mainly implemented in Swift but much of the functionality is written in Vist itself. All standard types—like ints, floats, and bools—are implemented in the standard library, as well as core language functionality like printing.

##Design

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




