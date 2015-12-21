#README #

##About
A simple programming language using LLVM written in Swift.


##Installing
To use, install the following with homebrew

``` 
brew update
brew install llvm
brew install llvm36
brew install homebrew/versions/llvm-gcc28
``` 

##Examples

```swift
func foo: (Int) -> Int = do return $0 + 1
func bar: (Int, Int) -> Int = |a, b| { return a + b }
```
