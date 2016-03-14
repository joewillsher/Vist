# Compilation overview

```swift
let a = 1
print a
```

A vist program is first transformed into a series of tokens: `let`, `identifier=“a”`, `assign`, `int_literal=1`, `identifier=“print”`, `identifier=“a”`.

These are then parsed to form an AST (abstract syntax tree).

```
                (declaration)
                /          \
            name=“a”	 (value)
                            |
                      int_literal=1
 
               (function call)
                /            \
     name=“print”           args:
                            - (variable) — name=“a”
```

I then run a semantic analysis pass, where I add type information to the tree and check it is valid Vist code. I fund out here that `a` has type `Int`, and `print`, a function in the standard library, has type `Int -> ()`.


	

```
type %Int = { %Builtin.Int64 }

func @main : () -> %Builtin.Void {
$entry:
  %0 = int_literal 1  	// uses: %1
  %1 = struct %Int (%0: %Builtin.Int64)  	// uses: %a, %2
  variable_decl %a = %1: %Int 
  %2 = call @print_Int (%1: %Int) 
  return ()
}

func @print_Int : (%Int) -> %Builtin.Void
```


```llvm
%Int.st = type { i64 }

define void @main() {
entry:
  %a = alloca %Int.st
  store %Int.st { i64 1 }, %Int.st* %a
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)
```

```llvm
tail call void @-Uprint_i64(i64 1)
```



```asm
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	"_-Uprint_i64"          ## TAILCALL
```

