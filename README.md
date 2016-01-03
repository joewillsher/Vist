#README #

##About
A programming language using LLVM, inspired by Swift, Haskell, and Rust.


##Installing
To use, install the following with homebrew

``` 
brew update
brew install llvm
brew install llvm36
brew install homebrew/versions/llvm-gcc28
``` 

Then clone this repo and run the Xcode project to build the compiler binary.

You can then run the compiler from the command line, use the `-h` flag to see options.

##Examples

```swift
func foo: Int Int -> Int = do
    return $0 + $1

func bar: Int = do print($0)

func fact: Int -> Int = |a| do
    if a <= 1 do
        return foo(0 1)
    else do
        return a * fact(a - 1)

type Baz {
    var a: Int
    let b: Int

    init Int Int = |x y| {
        a = x
        b = y
    }
    
    func foo: Int -> Int = do return a + b
}
```

##How it works



