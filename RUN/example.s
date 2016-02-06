	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, %eax
	movl	%eax, %edi
	popq	%rbp
	jmp	__$print_i64            ## TAILCALL

	.globl	__Bar_S.i64
	.align	4, 0x90
__Bar_S.i64:                            ## @_Bar_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq

	.globl	__Foo_S.S.i64
	.align	4, 0x90
__Foo_S.S.i64:                          ## @_Foo_S.S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	popq	%rbp
	retq


.subsections_via_symbols
