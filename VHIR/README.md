## VHIR: Vist’s high level intermediate representation

VHIR is the representation used to lower the AST to LLVM IR code. It bridges the gap between the AST and LLVM IR and is designed to more fluently reflect Vist’s type system & define the built in instructions it relies on.

# Example
```
func @add : (%Int64, %Int64) -> %Int64 {
#entry(%a: %Int64, %b: %Int64):
	%0 = $iadd %a: %Int64, %b: %Int64
	%1 = $iadd %0: %Int64, %b: %Int64
	%2 = $iadd %0: %Int64, %1: %Int64
	return %2
}
```


