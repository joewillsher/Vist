## VIR: Vist’s high level intermediate representation

VIR is the representation used to lower the AST to LLVM IR code. It bridges the gap between the AST and LLVM IR and is designed to more fluently reflect Vist’s type system & define the built in instructions it relies on.

### Motivation

```swift
let r = 5 as Any
if r the Int do
    print r
```

This example involves complex operations: construction of existentials, dynamic checks and branching, and emitting a shadow copy of r. VIR allows these to be represented in a high level language:

```
type #Any = existential {  } <>
type #Int = { #Builtin.Int64 }

witness_table #Int conforms #Any { }

func @main : &thin () -> #Builtin.Void {
$entry:
  %0 = int_literal 5 	// user: %1
  %1 = struct %Int, (%0: #Builtin.Int64) 	// user: %r
  %r = existential_construct %1: #Int in #Any 	// users: %7, %2
  cast_break %r: #*Any as #Int, $entry.cast0, $entry.exit // id: %2

$entry.cast0(%r: #*Int):			// preds: entry
  %3 = load %r: #*Int 	// user: %4
  %4 = call @_Vprint_tI (%3: #Int)
  dealloc_stack %r: #*Int // id: %5
  break $entry.exit // id: %6

$entry.exit:			// preds: entry, entry.cast0
  destroy_addr %r: #*Any // id: %7
  %8 = tuple () 	// user: %9
  return %8 // id: %9
}

func @_Vprint_tI : &thin (#Int) -> #Builtin.Void
```

Note how complex details of Vist are abstracted here:
- the `existential_construct` inst is lowered to runtime operations on `Int` and `Any`’s metadata
-  the `destroy_addr` inst is an instruction (emitted by the `ManagedValue` representing this object’s lifetime) which, depending on the type it destroys, can perform calls into the runtime to deallocate or release memory
- `cast_break` extracts the value from the existential container if at runtime it matches the type, it then breaks to the entry.cast0 block and passes in the ptr to the value. The inst is lowered to checks of the runtime metadata (stored in the existential) and optionally storing into the out-value.

The main function becomes:

```llvm
define void @main() {
entry:
  %0 = alloca %vist.existential
  ; our value
  %1 = alloca %Int
  store %Int { i64 5 }, %Int* %1
  ; construct the existential into %0; %1 is the value, @_gInts Int’s metadata, and @_gIntconfAny the Int’s conformance to Any
  %2 = bitcast %Int* %1 to i8*
  call void @vist_constructExistential(%vist.conformance* @_gIntconfAny, i8* %2, %vist.metadata* @_gInts, i1 false, %vist.existential* %0)
  %r1 = alloca %Int
  %3 = bitcast %Int* %r1 to i8*
  ; extract the value as an Int. If success, @vist_castExistentialToConcrete stores the value into %r1 and returns true
  %4 = call i1 @vist_castExistentialToConcrete(%vist.existential* %0, %vist.metadata* @_gInts, i8* %3)
  br i1 %4, label %entry.cast0, label %entry.exit

entry.cast0:                                      ; preds = %entry
  ; in this block, we can use the value in %r1
  %5 = load %Int, %Int* %r1
  call void @_Vprint_tI(%Int %5)
  br label %entry.exit

entry.exit:                                       ; preds = %entry.cast0, %entry
  ; destroy the existential
  call void @vist_deallocExistentialBuffer(%vist.existential* %0)
  ret void
}
```

If we went straight to this, we would lose information about the type of the Int stored in the existential and the control flow graph would be dependent on opaque runtime calls.

With the VIR optimisations, the emitted LLVM is:
```llvm
define void @main() {
entry:
  tail call void @_Vprint_tI(%Int { i64 5 })
  ret void
}
```

### Detail

A VIR Module contains function declarations, function definitions, types, and witness tables.

Types can be struct types, reference counted class types marked `refcounted`, and concept types marked `existential`. Types define their layout, and `existential` types define their required members and functions. After this, the types can declare lifetime management functions: `destroy`, `deepCopy`, and `deinit`; these are then stored in metadata and are used by the runtime to perform non trivial destruction, copying, and user defined deinitialisation behaviour respectively.

Functions definitions are declared with `func`, they must have a calling convention and type, and optionally a body. Function bodies consist of basic blocks, which are linear arrays of instructions with parameters which can be passed around. These basic block parameters replace other IR languages’ phi nodes, and they provide a nicer API for creating and optimising code, and are key to more complex instructions like `cast_break`. The entry point of a function gets its parameters passed in through the BB params of the entry block.

Witness tables explicitly represent concept conformances which can be implicit in Vist code — they map the requirement to the implementation for that type.


### Grammar

```
decl ::= vir-any-type-decl
vir-any-type-decl ::= 'type' type-name = (vir-existential-decl | type-name-decl) type-name-lifetime

type-name-layout ::= '{' (type-name (',' type-name)*)? '}'
type-name-requirements ::= '<' (vir-function '::' vir-function-type (',' vir-function '::' vir-function-type)*)? '>'

type-name-lifetime ::= '{' type-name-lifetime-member (',' type-name-lifetime-member)* '}'
type-name-lifetime-member ::= ('deinit' | 'dealloc' | 'deepCopy') ':' vir-function

vir-existential-decl ::= 'existential' type-name-layout type-name-requirements
type-name-decl ::= 'refcounted'? type-name-layout


type-name ::= '#' '*'* identifier
vir-function ::= '@' identifier
vir-function-type ::= '(' (type-name (',' type-name)*)? ')' '->' type-name
vir-block ::= '$' identifier

decl ::= func-decl
func-decl ::= 'func' vir-function ':' vir-func-convention vir-function-type vir-func-decl-body?
vir-func-decl-body ::= '{' basic-block* '}'

basic-block ::= vir-block vir-block-params? ':' inst-decl*
vir-block-params ::= '(' operand-list ')'


inst-decl ::= inst-name '=' inst
inst-name ::= '%' identifier | integer
operand ::= inst-name ':' type-name
operand-list ::= operand (',' operand)*


identifier ::= (a…z | A…Z | '_' | '$') (a…z | A…Z | '-' | '_' | '.')*
integer ::= ('+ | '-)? 0…9*
```

#### AllocInst

This allocates memory of a specified type.

```
inst ::= alloc-inst
alloc-inst ::= 'alloc' type-name
```

#### StoreInst

This stores a value into stack/heap memory.

```
inst ::= store-inst
store-inst ::= 'store' inst-name 'in' operand
```

#### LoadInst

Loads a value from memory

```
inst ::= load-inst
load-inst ::= 'load' operand
```

#### BitcastInst

Casts one pointer type to another

```
inst ::= bitcast-inst
bitcast-inst ::= 'bitcast' operand 'to' type-name
```

#### DestoryAddrInst

This instruction destroys the value stored in memory; its lowering is dependent on the type of the value stored in it:
- if the operand is an existential, its buffer is destroyed using vist_deallocExistentialBuffer
- If the operand is a ref type, it is released
- if the operand is any other type with an explicit destructor function, that is called. This should be used to destroy the values stored in the fields of that type

```
inst ::= destroy-addr-inst
destroy-addr-inst ::= 'destroy_addr' operand
```

#### DestroyValInst

Like destroy_addr but works on a value, should not be used on ref types as their identity only exists as a heap pointer.
```
inst ::= destroy-val-inst
destroy-val-inst ::= 'destroy_val' operand
```

#### CopyAddrInst

This copies one ptr value to another location, the lowering depends on the operand type:
- trivial types are shallowly copied
- Ref types are retained then copied
- existentials and non trivial types are copied using their 'deepCopy' copy constructor

```
inst ::= copy-addr-inst
copy-addr-inst ::= 'copy_addr' operand 'to' operand
```

#### DeallocStackInst

This is a noop, it is emitted by VIRGen so that the optimiser can replace it with another destructor operation if it later needs it.

```
inst ::= dealloc-stack-inst
dealloc-stack-inst ::= 'dealloc_stack' operand
```

#### BuiltinInst

These are a collection of insts properly defined by lower stages of the compiler; LLVM defines primitives to add/sub/and integers, and these are lowered to calls to them.

These can all be called from vist code in the stdlib using calls to Builtin.intrinsic_name.

```
inst ::= builtin-inst
builtin-inst ::= 'builtin' builtin-name operand-list
builtin-inst ::= 'cond_fail' operand

builtin-name ::= 'i_add' | 'i_sub' | 'i_mul' | 'i_div' | 'i_rem' | 'i_eq' | 'i_neq' | 'b_eq' | 'b_neq' | 'i_add_unchecked' | 'i_mul_unchecked' | 'i_pow' | 'i_cmp_lte' | 'i_cmp_gte' | 'i_cmp_lt' | 'i_cmp_gt' | 'i_shl' | 'i_shr' | 'i_and' | 'i_or' | 'i_xor' | 'b_and' | 'b_or' | 'b_not' | 'expect' | 'trap' | 'stack_alloc' | 'heap_alloc' | 'heap_free' | 'mem_copy' | 'opaque_store' | 'advance_pointer' | 'opaque_load' | 'f_add' | 'f_sub' | 'f_mul' | 'f_div' | 'f_rem' | 'f_eq' | 'f_neq' | 'f_cmp_lte' | 'f_cmp_gte' | 'f_cmp_lt' | 'f_cmp_gt' | 'trunc_int_8' | 'trunc_int_16' | 'trunc_int_32' | 'with_ptr' | 'is_uniquely_referenced' | 'sext_int_64'
```

The `cond_fail` inst traps if the bool value is true.

#### AllocObjectInst

Allocates a heap object of a specified class type, returns a RC=1 ptr.

```
inst ::= alloc-object-inst
alloc-object-inst ::= 'alloc_object' type-name
```

#### RetainInst

Increments an object’s reference count.

```
inst ::= retain-inst
retain-inst ::= 'retain' operand
```

#### ReleaseInst

Decrements an object’s reference count, and deallocates it if it falls to 0.

```
inst ::= release-inst
release-inst ::= 'release' operand
```

#### DeallocObjectInst

Deallocates a heap object.

```
inst ::= dealloc-object-inst
dealloc-object-inst ::= 'dealloc_object' operand
```


#### FunctionCallInst

Calls a function.

```
inst ::= call-inst
call-inst ::= 'call' function-name '(' operand-list ')'
```

#### FunctionApplyInst

Calls a function ptr stored as a local variable.

```
inst ::= apply-inst
apply-inst ::= 'apply' operand '(' operand-list ')'
```

#### FunctionRefInst

Gets a ptr to a global function.

```
inst ::= function-ptr-inst
function-ptr-inst ::= 'function_ref' function-name
```

#### IntLiteralInst

An int literal, 64 bits wide, is of type Builtin.Int64.

```
inst ::= int-literal-inst
int-literal-inst ::= 'int_literal' integer
```

#### BoolLiteralInst

An bool literal, is of type Builtin.Bool.

```
inst ::= bool-literal-inst
bool-literal-inst ::= 'bool_literal' 'true' | 'false'
```

#### StringLiteralInst

A string literal with a defined encoding.
```
inst ::= string-literal-inst
string-literal-inst ::= 'string_literal' ('utf8' | 'utf16') string
```

#### ReturnInst

```
inst ::= return-inst
return-inst ::= 'return' operand
```

#### StructInitInst

Initialises a struct aggregate of a specified type.

```
inst ::= struct-inst
struct-inst ::= 'struct' type-name ',' '(' operand-list ')'
```

#### StructExtractInst

Load a value from a struct aggregate.

```
inst ::= struct-extract-inst
struct-extract-inst ::= 'struct_extract' operand ',' '!' identifier
```

### StructElementPtrInst

Get a ptr to a field of a struct passed by ptr.

```
inst ::= struct-gep-inst
struct-gep-inst ::= 'struct_element' operand ',' '!' identifier
```

#### ClassProjectInstanceInst

Get the ptr to the instance of a heap allocated ref type.

```
inst ::= class-project-inst
class-project-inst ::= 'class_project_instance' operand
```

#### ClassGetRefCountInst

Get the ref count of a heap allocated ref type.

```
inst ::= class-refcount-inst
class-refcount-inst ::= 'class_get_refcount' operand
```

#### TupleCreateInst

Initialises a tuple aggregate of a specified type.
```
inst ::= tuple-inst
tuple-inst ::= 'tuple' type-name ',' '(' operand-list ')'
```

#### TupleExtractInst

Load a value from a tuple aggregate.

```
inst ::= tuple-extract-inst
tuple-extract-inst ::= 'tuple_extract' operand ',' '!' identifier
```

### TupleElementPtrInst

Get a ptr to a field of a tuple passed by ptr.

```
inst ::= tuple-gep-inst
tuple-gep-inst ::= 'tuple_element' operand ',' '!' integer
```

#### VariableInst

A debug value is a named reference to another variable.

```
inst ::= variable-inst
variable-inst ::= 'variable' '%' 'identifier' '=' operand
```

#### VariableAddrInst

A debug value is a named reference to another variable. A variable addr is a reference to a possibly mutable piece of memory.

```
inst ::= variable-addr-inst
variable-addr-inst ::= ('variable_addr' | 'mutable_variable_addr') '%' 'identifier '=' operand
```

#### BreakInst

Break to another basic block, optionally passing it operands.

```
inst ::= break-inst
break-inst ::= 'break' block-name ( '(' operand-list ')' )?
```

#### CondBreakInst 

Break to one of 2 basic blocks, depending on the value of a boolean operand.

```
inst ::= cond-break-inst
cond-break-inst ::= 'cond_break' operand ',' block-name ( '(' operand-list ')' )? ',' block-name ( '(' operand-list ')' )?
```

#### CheckedCastBreakInst

Break to one of 2 basic blocks, checking at runtime whether an erased value is a type. A call must specify the expected type, and passes the extracted value by ptr into the success block.

```
inst ::= cast-break-inst
cast-break-inst ::= 'cast_break' operand 'as'  type-name ',' block-name ( '(' operand-list ')' )? ',' block-name ( '(' operand-list ')' )?	
```

#### ExistentialProjectPropertyInst

Opening an existential box to get a pointer to a member.

```
inst ::= existential-project-property-inst
existential-project-property-inst ::= 'existential_project_member' operand ',' '!' identifier
```

#### ExistentialConstructInst

Constructing an existential box from a conforming instance. The nonlocal specifier can be added to make sure this is allocated on the heap.

```
inst ::= existential-construct-inst
existential-construct-inst :: = ('existential_construct' | 'existential_construct_nonlocal') operand 'in' type-name
```

#### ExistentialWitnessInst

Get a witness method from an existential.

```
inst ::= witness-method-inst
witness-method-inst ::= 'existential_witness' operand ',' '!' identifier
```

#### ExistentialProjectInst

Project the value stored in an existential buffer.

```
inst ::= existential-project-inst
existential-project-inst ::= 'existential_project' operand
```


#### ExistentialExportBufferInst

Export an existential buffer to the heap.

```
inst ::= export-existential-inst
export-existential-inst ::= 'existential_export_buffer' operand
```


