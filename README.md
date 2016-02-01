#README #

##About
A programming language using LLVM, inspired by Swift, Haskell, and Rust.


##Installing
To use, install the following with homebrew

``` 
brew update
brew install llvm --with-clang
``` 

Then clone this repo and run the Xcode project to build the compiler binary.

To run the binary in Xcode, go to ‘Edit Scheme’ (⌘<) and set the *arguments* to `-O -verbose -preserve example.vist` and under *Options* set the ‘Custom Working Directory’ to `$(SRCROOT)/RUN`

Or you can then run the compiler from the command line, use the `-h` flag to see options.

##Examples

```swift
func foo :: Int Int -> Int = do
    return $0 + $1

func bar :: Int = do print $0

func fact :: Int -> Int = (a) do
    if a <= 1 do
        return 1
    else do
        return a * fact a - 1

print (foo 100 (fact 10))

type Baz {
    var a: Int
    let b: Int
    
    func foo :: Int -> Int = do 
        return $0 * (a + b)
}

let baz = Baz 1 4
let x = baz.foo 2
print x

```

##How It Works

Vist is a strongly typed language which compiles to [LLVM’s](https://en.wikipedia.org/wiki/LLVM#LLVM_Intermediate_Representation) [IR](http://llvm.org/docs/LangRef.html)—a high level assembly language. Vist’s compiler structure was inspired by the implementation of other languages such as [Rust](https://github.com/rust-lang/rust) and particularly [Swift](https://github.com/apple/swift).

The compile process involves transforming the source code from one representation to another—the text is [lexed](https://en.wikipedia.org/wiki/Lexical_analysis) into a series of tokens, which is [parsed](https://en.wikipedia.org/wiki/Parsing#Computer_languages) to form the [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree). The [semantic analysis](https://en.wikibooks.org/wiki/Compiler_Construction/Semantic_Analysis) pass then walks the tree, adding type information, and then to generate the IR code.

[Like Swift](http://arstechnica.com/apple/2014/10/os-x-10-10/22/), Vist tries to keep the standard library defined separately from the compiler; this allows the language implementation to be separated from its compilation which while theoretically more elegant, imposes implementation obstacles. The difficulty here is maintaining performance—I need to guarantee that calls to these functions will be transformed into the native calls and that they will be inlined *as early as possible*.

The standard library has access to a special set of native functions and types with prefix `LLVM.` For example, the standard library’s `+` operator is [defined as](Vist/stdlib/stdlib.vist):

```swift
@inline @operator(80)
func + :: Int Int -> Int = (a b) {
	let v = LLVM.i_add a.value b.value
	condFail v.1
	return Int v.0
}
```

The call to `LLVM.i_add` returns a tuple of type `(Int Bool)`—the first element is used as a check for overflow, which is done by a call to the stdlib’s `condFail` function. Then the result (of type LLVM.Int64) is wrapped in an Int type using Int’s initialiser.

The Int type has 1 property `value` of type `LLVM.Int64`, which is the native hardware supported i64 object. The stdlib functions which take `Int`s (such as `+`) extract this value using to pass into the hardware supported functions. Vist automatically generates a *memberwise initialiser* for any object which takes the parameters of the structs elements.

This is how the compiler turns literals like `50`, `true`, and `40.1` into the Int, Bool, and Double types the Vist writers can use; the compiler gets special knowledge of these initialisers and functions existing [baked into it](Vist/AST/StdLibDef.swift), and wraps any literal with a call to that function. This means code like

```
let a = 1 + 2
print a
```

ends up getting transformed into

```LLVM
define void @main() {
entry:
	%0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
	%1 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
	%"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %0, { i64 } %1), !stdlib.call.optim !0
	call void @_print_S.i64({ i64 } %"+.res"), !stdlib.call.optim !0
	ret void
}
```

This is obviously too complicated! Our efforts to simplify the compiler’s architecture has led to our IR getting much more complex, and our generated program slower. Moreover, our added indirection is stopping important optimisations being performed—as LLVM’s optimiser has no knowledge of what `_+_S.i64_S.i64` (the `+` function’s mangled name) does, it cannot reason about its behaviour, and fold the `1 + 2` to a `3` operation as we would hope.

To get around this, I have [an optimisation pass](Vist/Optimiser/StdLibInline.cpp) which (when it sees the `!stdlib.call.optim` metadata on any of my stdlib functions) can extract its implementation from a LLVM [(bitcode)](http://llvm.org/docs/BitCodeFormat.html) file of of my [stdlib](Vist/StdLib/stdlib.ll), and inlines it before the rest of the optimisations. This means our program can become

```llvm
define void @main() #0 {
entry:
	tail call void @"_$print_i64"(i64 3)
	ret void
}
```

Much better, I’d say.

Here, inlining the integer’s initialisers has let the optimiser know what is going on inside that little struct, which means it can see through all the [`insertvalue`](http://llvm.org/docs/LangRef.html#insertvalue-instruction) and [`extractvalue`](http://llvm.org/docs/LangRef.html#extractvalue-instruction) instructions (made by calling my `Int` initialiser and by getting the raw value using `.value`), flattening my structs and allowing it to reduce it to a final on a `i64 3`, a native object.

Even better, inlining the `+` function lets [the optimiser](http://llvm.org/docs/Passes.html) get rid of my conditional branches (from the overflow checks), and even lets the `llvm.sadd.with.overflow.i64` call be calculated statically!

All thats left is a call to the `_$print_i64` function—one of the [runtime functions](Vist/Runtime/Runtime.cpp) which just calls `printf` from the c standard library on my number.

And thats it, we now link my code with the standard library (to allow some last minute, link-time optimisations) and assemble the object files to generate the executable.



