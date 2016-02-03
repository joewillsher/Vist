#README #

##About
A programming language using LLVM, inspired by Swift, Haskell, and Rust.


##Installing
To use, install the following with homebrew

``` bash
brew update
brew install llvm --with-clang
``` 

Then clone this repo and run the Xcode project to build the compiler binary.

To work on it in Xcode, go to ‘Edit Scheme’ (⌘<) and set the *arguments* to `-O -verbose -preserve example.vist` and under *Options* set the ‘Custom Working Directory’ to `$(SRCROOT)/RUN`.

Alternatively, after building it, you can then run the compiler from the command line, use the `-h` flag to see all options.

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
##Architecture overview

Vist is a strongly typed language which compiles to [LLVM’s](https://en.wikipedia.org/wiki/LLVM#LLVM_Intermediate_Representation) [IR](http://llvm.org/docs/LangRef.html)—a high level (so mostly architecture agnostic), typed, [SSA](https://en.wikipedia.org/wiki/Static_single_assignment_form) assembly language. Vist’s compiler structure was inspired by the implementation of other languages such as [Rust](https://github.com/rust-lang/rust) and particularly [Swift](https://github.com/apple/swift).
 
The compile process involves transforming the source code from one representation to another—the text is [lexed](https://en.wikipedia.org/wiki/Lexical_analysis) into a series of tokens, which is [parsed](https://en.wikipedia.org/wiki/Parsing#Computer_languages) to form the [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree). The [semantic analysis](https://en.wikibooks.org/wiki/Compiler_Construction/Semantic_Analysis) pass then walks the tree, adding type information, and then to generate the IR code.

The [lexing](../VistLexer/Lexer.swift) separates Vist’s keywords and characters into a stream of tokens. [Parsing](../VistAST/Parser.swift) extracts the program’s meaning, and constructs the [AST](../VistAST/Expr.swift). The [sema](../VistSema/Sema.swift) pass type checks the source and does other static checks, like making sure variables are declared before they’re used. The [IRGen](../VistIRGen/IRGen.swift) phase then creates the LLVM IR code, which is optimised and compiled.


##Writing

I am writing about compilers and the development of Vist.

- [Abstraction & Optimisation](Posts/Abstraction_and_Optimisation.md)


