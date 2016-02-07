	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$12, %eax
	movl	%eax, %edi
	callq	__$print_i64
	movl	$3, %eax
	movl	%eax, %edi
	callq	__$print_i64
	movl	$1, %edi
	popq	%rbp
	jmp	__$print_b              ## TAILCALL

	.globl	__StackOf2_S.i64_S.i64
	.align	4, 0x90
__StackOf2_S.i64_S.i64:                 ## @_StackOf2_S.i64_S.i64
## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, %rax
	movq	%rsi, %rdx
	popq	%rbp
	retq


.subsections_via_symbols
