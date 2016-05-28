## VIR: Vist’s high level intermediate representation

VIR is the representation used to lower the AST to LLVM IR code. It bridges the gap between the AST and LLVM IR and is designed to more fluently reflect Vist’s type system & define the built in instructions it relies on.

# Example

```
func @add_tII : (%Int, %Int) -> %Int {
#entry(%a: %Int, %b: %Int):
	%0 = $i_add %a: %Int, %b: %Int
	%1 = $i_add %0: %Int, %b: %Int
	%2 = $i_add %0: %Int, %1: %Int
	return %2
}
```


