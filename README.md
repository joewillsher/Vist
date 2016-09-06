#README #

![](https://travis-ci.org/joewillsher/Vist.svg?branch=master)

##About
A functional, statically typed programming language using LLVM, inspired by Swift, Haskell, and Rust. Vist has a friendly & low weight syntax, and modern type system with a focus on concepts, and plans for generics.


##Installing
Vist is is written in Swift 3 and compiles under the most recent Xcode beta.

To install, run

``` bash
git clone https://github.com/joewillsher/Vist.git
cd vist
./utils/build
``` 

This downloads the LLVM libraries, builds the libvist standard library and runtime and installs the compiler. To use it call `vist` from the command line, use `-h` to see options.


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

Vist is a high level and strongly typed language aimed at being concise, flexible, and safe. The Vist AST is lowered to VIR, a high level intermediary representation which will allows optimisations specific to Vist’s semantics. For example VIR has high level instructions like checked cast branches, retain/release operations, and it abstracts the code which interacts with the runtime to create and copy existential concept objects. It exposes the `existential_construct`, `copy_addr`, and `destroy_addr` instructions which construct, move, and copy the existential buffer. The VIR optimiser has special knowledge of these instructions, so can elide unnecessary copies, promote the existential to the stack, or remove the existential box if allowed.

The Vist compiler is mainly implemented in Swift but much of the functionality is written in Vist itself. All standard types—like ints, floats, and bools—are implemented in the standard library, as well as core language functionality like printing.

The runtime allows for much of vist’s dynamic behaviour: types which conform to a concept have a ‘witness table’ which is read by the runtime to emit calls to the concept’s methods and to copy or delete complex objects. This type metadata can also be read by the user, using the `typeof` function, and the runtime can perform dynamic type casts to allow patterns like `if x the Int do print x`.

LLVM is used for code generation, but there is experimental work to replace it with vist’s own backend. Here, LLVM IR is replaced by an assembly intermediate language (AIR), which can be used for instruction selection.


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

Vist’s type system is based around *concepts* and *generics*. Concepts describe what a type can do—its properties and methods. Concepts can be used as existentially as types, and eventually as generic constraints.
```swift
concept TwoInts {
    var a: Int, b: Int
}

func sum :: TwoInts Int -> Int = (x y) do
    return x.a + y + x.b
```

You can cast objects from one type to another, and introspect a type:

```swift
func foo :: Any = (val) do
	if val the Int do
		print val + 1

func foo :: Box = (box) do
	if p the Printable = box.field do
		print p

func foo :: Any = (some) do
	print ((typeof some).name ()) // > "String"
```
