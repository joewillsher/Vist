#README #

##About
A programming language using LLVM, inspired by Swift, Haskell, and Rust.


##Installing
To use, install the following with homebrew

``` 
brew update
brew install llvm
``` 

Then clone this repo and run the Xcode project to build the compiler binary.

To run the binary in Xcode, go to ‘Edit Scheme’ (⌘<) and set the *arguments* to `-O -verbose -preserve example.vist` and under *Options* set the ‘Custom Working Directory’ to `$(SRCROOT)/RUN`

Or you can then run the compiler from the command line, use the `-h` flag to see options.

##Examples

```swift
func foo :: Int Int -> Int = do
    return $0 + $1

func bar :: Int = do print $0

func fact :: Int -> Int = |a| do
    if a <= 1 do
        return 1
    else do
        return a * fact a - 1

print (foo 100 (fact 10))

type Baz {
    var a: Int
    let b: Int
    
    func foo :: Int -> Int = do return $0 * (a + b)
}

let baz = Baz 1 4
let x = baz.foo 2
print x

```

##How it works



