## VHIR: Vist’s high level intermediate representation

VHIR is the representation used to lower the AST to LLVM IR code. It solves the p


```
func @add : (%Int64, %Int64) -> %Int64 {
#entry(%a: %Int64, %b: %Int64):
	%0 = $iadd %a: %Int64, %b: %Int64
	%1 = $iadd %0: %Int64, %b: %Int64
	%2 = $iadd %0: %Int64, %1: %Int64
	return %2
}
```

